/**
 * Project Untitled
 */


#ifndef _DIRECTION_H
#define _DIRECTION_H
#include "utility"
using Direction = std::pair<int, int>;
/**
  Different possible direction and the value
 * @brief The _direction struct
 */
struct _direction {
    static constexpr const Direction RIGHT_DOWN{-1, 1};
    static constexpr const Direction RIGHT_UP{1, 1};
    static constexpr const Direction LEFT_DOWN{-1, -1};
    static constexpr const Direction LEFT_UP{1, -1};
    static constexpr const Direction RIGHT_LATERAL{0, 2};
    static constexpr const Direction LEFT_LATERAL{0, -2};
};
#endif //_DIRECTION_H
