namespace LMacros
{
	#define LFREE(ptr) { if(ptr != nullptr) { (ptr); ptr = nullptr; } };
}
