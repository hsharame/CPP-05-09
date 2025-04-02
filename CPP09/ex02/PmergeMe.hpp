/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:49:20 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/02 18:08:21 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe& operator=(PmergeMe const &rhs);

		void	setInput(std::vector<int> toSet);
		std::vector<int>& getInput();
		void	setSorted(std::deque<int> toSet);
		std::deque<int> getSorted() const;

	private:
		std::vector<int> _input;
		std::deque<int> _sorted;
};

#endif
