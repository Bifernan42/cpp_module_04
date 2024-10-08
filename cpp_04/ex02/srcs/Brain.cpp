#include "../includes/Brain.hpp"

Brain::Brain(): ideas_num(0)
{
	std::cout << "Brain : default constructor called\n";
}

Brain::Brain(const Brain & other)
{
    for (int i = 0 ; i < 100 ; ++i)
    {
        this->ideas[i] = other.ideas[i];
    }
    this->ideas_num = other.ideas_num;
    std::cout << "Brain : copy constructor called\n";
}

Brain &Brain::operator=(const Brain & other)
{
    std::cout << "Brain : copy assignment overload called\n";
    if (this != &other)
    {
        for (int i = 0 ; i < 100 ; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
        this->ideas_num = other.ideas_num;
    }
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain : destructor called\n";
}

void Brain::add_idea(const std::string &new_idea)
{
    if (ideas_num < 100)
    {
        ideas[ideas_num] = new_idea;
        ideas_num++;
    }
    else {
        std::cout << "Brain : full capacity reached !\n";
    }
}

void Brain::express_ideas() const
{
    for (int i = 0; i < ideas_num; ++i)
    {
        std::cout << "Brain : " << "* " << ideas[i] << " *" << std::endl;
    }
}
