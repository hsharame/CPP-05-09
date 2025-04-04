/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:49:20 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/04 18:43:50 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe& operator=(PmergeMe const &rhs);
		
		void	sortVector(std::vector<int>& v);
		void	sortDeque(std::deque<int> &d);
		void	setInputV(std::vector<int> toSet);
		std::vector<int>& getInputV();
		void	setInputD(std::deque<int> toSet);
		std::deque<int>& getInputD();
		
		void	setSortedV(std::vector<int> toSet);
		std::vector<int>& getSortedV();
		void	setSortedD(std::deque<int> toSet);
		std::deque<int>& getSortedD();
		
		void	setError(bool v);
		bool	&getError();

		double	getTimeV() const;
		double	getTimeD() const;
		
	private:
		std::vector<int> _inputV;
		std::deque<int> _inputD;
		
		std::vector<int> _sortedV;
		std::deque<int> _sortedD;
		
		double	_timeV;
		double	_timeD;

		bool			_error;
};

#endif
