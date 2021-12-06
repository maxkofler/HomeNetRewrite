#ifndef __ARGS_H__
#define __ARGS_H__

#include <string>
#include <vector>

class Args{

public:
	Args();
	Args(std::vector<std::string>);

	/**
	 * @brief	Get the argument at the specified position
	 * @param	index			The index to get the string from
	 * @return	The string at the position, empty if out of bounds
	 */
	std::string					at(size_t index);

	/**
	 * @brief	Returns the amount of arguments
	 */
	size_t						size();

private:

	std::vector<std::string>	_args;

};

#endif
