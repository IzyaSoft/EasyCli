#ifdef WIN32
    #define EXPORT __declspec(dllexport)
    #pragma warning(disable:4251) // warning like: class 'std::shared_ptr<>' needs to have dll-interface to be used by clien
#else
    #define EXPORT
#endif