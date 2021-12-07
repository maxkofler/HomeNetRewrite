#ifndef __ARGS_H__
#define __ARGS_H__

#include <string>
#include <vector>

class Args{

public:
	Args();
	Args(std::vector<void*>);

	/**
	 * @brief	Get the argument at the specified position
	 * @param	index			The index to get the string from
	 * @return	The string at the position, empty if out of bounds
	 */
	std::string					at(size_t index);

	/**
	 * @brief	Appends the provided argument to the argument list
	 * @param 	arg 			A pointer to the argument, the memory does not get managed!
	 */
	void						addArg(void* arg);

	/**
	 * @brief	Returns the amount of arguments
	 */
	size_t						size();

private:

	std::vector<void*>			_args;

};

#endif
