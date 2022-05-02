/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:52 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/02 16:28:24 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetFirstName(std::string fn)
{
	_firstName = fn;
}

std::string	Contact::GetFirstName()
{
	return _firstName;
}

void	Contact::SetLastName(std::string ln)
{
	_lastName = ln;
}

std::string	Contact::GetLastName()
{
	return _lastName;
}

void	Contact::SetNickName(std::string nn)
{
	_nickName = nn;
}

std::string	Contact::GetNickName()
{
	return _nickName;
}

void	Contact::SetPhoneNumber(std::string pn)
{
	_phoneNumber = pn;
}

std::string	Contact::GetPhoneNumber()
{
	return _phoneNumber;
}

void	Contact::SetDarkestSecret(std::string ds)
{
	_darkestSecret = ds;
}

std::string	Contact::GetDarkestSecret()
{
	return _darkestSecret;
}
