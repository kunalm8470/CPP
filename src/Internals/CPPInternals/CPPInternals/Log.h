/*
	This is a header guard, which essentially prevents us from loading the same header
	file multiple times in a single translation unit.
*/
#pragma once

void Log(const char* message);

/*
	An alternative would be, to simply use #ifndef which checks 
	on a symbol if defined or not if defined it won't 
	add it into the translation unit again.

	#ifndef _LOG_H
	#define _LOG_H

	void Log(const char* message);
	
	#endif
*/