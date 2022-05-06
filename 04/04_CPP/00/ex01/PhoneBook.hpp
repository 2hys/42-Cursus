/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:21:48 by jiychoi           #+#    #+#             */
/*   Updated: 2022/05/06 12:11:29 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	private:
		int curIndex;
		Contact contactArr[8];
	public:
		PhoneBook(void);
		void AddNewContact();
		void SearchContact();
};
