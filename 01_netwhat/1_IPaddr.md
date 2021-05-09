# What is an IP Address?
IP 주소란 무엇인가?

## Protocol
- 통신 규약
- 수신자 (Receiver) 와 발신자 (Sender) 상호 간의 규칙
- 이것을 지킴으로써 통신을 효율적으로 진행하거나, 특정 목적을 달성한다
- 굳이 통신 규약이 있는 이유는, 컴퓨터나 전자 기기 등은 모두 운영체제나 구현된 언어가 다르기 때문에 네트워크에서만큼은 이들이 통신하기 위해 하나의 공통된 프로토콜이 필요했기 때문
	- 원래는 장비 제조사마다 서로 다른 프로토콜을 사용했으나, 다른 회사의 장비끼리의 통신도 구현하기 위해 국제 표준을 위한 ISO 위원회가 발족되고 TCP/IP가 전 세계 표준이 되었다

## IP 주소
- Internet Protocol
- 네트워킹이 가능한 장비를 식별하는 주소
	- 이때 네트워킹이 가능한 장비는 PC, 서버용 장비, 스마트폰 등 인터넷에 연결되는 모든 장비
	- 장비들의 주민등록번호 같은 느낌이다
- 네트워크에서 통신을 하기 위해선 통신 규약 (프로토콜) 을 따라야 함
	- 이때 이러한 통신 규약 중 하나가 **장비들에게 숫자 12개의 고유 주소를 주어서 통신 상대를 구분할 것** 이다 (IPv4)
- 000.000.000.000
	- 이렇게 12자리 주소가 통신기기에 부여되기 때문에 프로토콜을 지킨 걸로 간주되어 인터넷이 가능케 됨
	- 각 3개의 숫자는 8비트씩 변환할 수 있다 (000 ~ 255)
	```
	192.		168.		0.			1
	11000000. 	10101000.	00000000. 	00000001
	```
	- 각 8비트 숫자는 옥텟이라고 부른다 (물론 이진수가 알아보기 힘들어서 십진수로 쓰는 것)
	- 앞의 세 자리는 네트워크 주소, 마지막 한 자리는 호스트 IP이다
- IPv6이라고 더 긴 버전도 있는데 (IPv4의 40억개가 부족하다고 판단되어서 늘어난 결과) 이것은 아직 많이 보급되지 않은듯