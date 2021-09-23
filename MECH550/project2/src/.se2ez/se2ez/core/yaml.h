/* Author: Zachary Kingston */

#ifndef SE2EZ_CORE_YAML_
#define SE2EZ_CORE_YAML_

#include <se2ez/core/class_forward.h>

namespace se2ez
{
    /** \cond IGNORE */
    SE2EZ_CLASS_FORWARD(Robot)
    SE2EZ_CLASS_FORWARD(State)
    /** \endcond */

    namespace io
    {
        /** \brief Loads a robot from a YAML file.
         *  \param[in] filename The filename to load.
         *  \return A robot compiled from filename, and a nullptr on failure.
         */
        RobotPtr loadRobot(const std::string &filename);

        /** \brief Loads named robot states from a YAML file.
         *  \param[in, out] robot Robot to load named states into.
         *  \param[in] filename The filename to load.
         *  \return True on success, false on failure.
         */
        bool loadNamedStates(RobotPtr robot, const std::string &filename);

        /** \brief Loads robot states from a YAML file.
         *  \param[in] robot Robot to load states as.
         *  \param[in] filename The filename to load.
         *  \return A vector of the states.
         */

        std::vector<StatePtr> loadStates(const RobotPtr &robot, const std::string &filename);

        /** \brief Stores given robot states to a YAML file.
         *  \param[in] robot Robot the states belong to.
         *  \param[in] states StatePtr vector to store in the yaml file.
         *  \param[in] filename The filename to store.
         */
        void storeStates(const RobotPtr &robot, const std::string &filename,
                         const std::vector<StatePtr> &states);

    }  // namespace io
}  // namespace se2ez

#endif
