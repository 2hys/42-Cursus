from django.shortcuts import render
from django.shortcuts import redirect
from . import game
import random


# Create your views here.
def world_load(setting, state=None):
    newdata = game.GameData()
    if state == 'new':
        newdata.load_default_settings(setting)
        newdata.dump('temp')
    newdata.load('temp')
    return newdata


def world_move(data, ctrl):
    if ctrl == 'n' and data.coord_y > 0:
        data.coord_y -= 1
        data.move_dir = 'n'
    elif ctrl == 'w' and data.coord_x > 0:
        data.coord_x -= 1
        data.move_dir = 'w'
    elif ctrl == 's' and data.coord_y < data.size - 1:
        data.coord_y += 1
        data.move_dir = 's'
    elif ctrl == 'e' and data.coord_x < data.size - 1:
        data.coord_x += 1
        data.move_dir = 'e'


def world_context(data, setting, flag):
    table_size = [i for i in range(0, data.size)]
    btn_a = "location.href='';"
    width = 700 / data.size
    monster_id = None
    if flag == 2:
        monster_id = data.get_random_movie(setting.movie_db)
        btn_a = "location.href='/battle/" + monster_id + "';"
    dic = {
        'coord_x': data.coord_x,
        'coord_y': data.coord_y,
        'move_dir': data.move_dir,
        'table_row': table_size,
        'table_col': table_size,
        'btn_north': "location.href='?ctrl=n';",
        'btn_west': "location.href='?ctrl=w';",
        'btn_east': "location.href='?ctrl=e';",
        'btn_south': "location.href='?ctrl=s';",
        'btn_a': btn_a,
        'btn_b': "location.href='';",
        'btn_start': "location.href='/options/';",
        'btn_select': "location.href='/moviedex/';",
        'flag': flag,
        'width': width,
        'movieball': data.ball,
    }
    return dic


def world_random_event(data, setting):
    rand_seed = random.randrange(1, 11)
    if len(data.catched_movie) == len(list(setting.movie_db.keys())):
        return 3
    elif rand_seed < 3:
        data.ball += 1
        return 1
    elif rand_seed > 8:
        return 2
    else:
        return 0


def worldmap(request):
    event_flag = 0
    temp_data = game.GameData()
    temp_data.load('temp')
    temp_setting = game.SettingData()
    if temp_data.status_world is not None:
        context = world_context(temp_data, temp_setting, temp_data.status_world)
        temp_data.status_world = None
        temp_data.dump('temp')
        return render(request, 'moviemon/worldmap.html', context)
    state = request.GET.get('from', None)
    ctrl = request.GET.get('ctrl', None)
    temp_data = world_load(temp_setting, state)
    world_move(temp_data, ctrl)
    event_flag = world_random_event(temp_data, temp_setting)
    temp_data.index = 0
    temp_data.dump('temp')
    if state is not None or ctrl is not None:
        temp_data.status_world = event_flag
        temp_data.dump('temp')
        return redirect(request.path)
    context = world_context(temp_data, temp_setting, event_flag)
    return render(request, 'moviemon/worldmap.html', context)

