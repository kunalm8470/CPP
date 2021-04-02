#pragma once
namespace foo {
	int doOther(int a, int b) {
		return a % b;
	}
}

/*
    Nested namespace
*/
namespace bar
{
    namespace baz
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}