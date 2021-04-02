extern int global_var;

/*
	Forward referencing a scoped enum
*/
enum class Color : unsigned int
{
	RED = 2,
	BLUE = 4,
	GREEN = 6
};
