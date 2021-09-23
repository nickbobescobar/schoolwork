/* Author: Zachary Kingston */

#ifndef SE2EZ_CORE_CLASS_FORWARD_
#define SE2EZ_CORE_CLASS_FORWARD_

#include <Eigen/Core>
#include <memory>

#define SE2EZ_CLASS_FORWARD(C)                                                                               \
    class C;                                                                                                 \
    typedef std::shared_ptr<C> C##Ptr;                                                                       \
    typedef std::shared_ptr<const C> C##ConstPtr;

#define SE2EZ_EIGEN_CLASS EIGEN_MAKE_ALIGNED_OPERATOR_NEW

#endif
