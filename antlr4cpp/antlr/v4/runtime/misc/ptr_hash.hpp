#pragma once

#include <functional>

namespace antlr4 {
namespace runtime {
namespace misc {

	template<typename _Tptr, typename _Hasher = std::hash<std::remove_reference<decltype(*_Tptr())>::type>>
	struct ptr_hash : public std::unary_function<_Tptr, size_t>
	{
		typedef typename std::conditional<std::is_pointer<_Tptr>::value, _Tptr, _Tptr const&>::type param_type;

		size_t operator() (param_type value) const
		{
			if (!value)
			{
				return std::hash<void*>()(nullptr);
			}

			return _Hasher()(*value);
		}
	};

}
}
}