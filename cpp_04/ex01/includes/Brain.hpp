#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
		int   ideas_num;
	public:
		Brain();
		Brain(const Brain &);
		Brain &operator=(const Brain &);
		~Brain();
		void add_idea(const std::string &);
		void express_ideas() const;
};

#endif
