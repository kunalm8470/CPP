struct S
{
	char c{};
	int a{};
};

/*
	Since headers files can be included in
	multiple cpp files, which can lead to duplicate code
	and violation of One definition Rule (ODR) in C++
	in the linking stage, hence just keep the declaration
	in the header file (essentially just keeping the prototype / forward-reference)
*/
void initialize_S(S& s);
