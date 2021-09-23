/* Author: Zachary Kingston */

#ifndef SE2EZ_PLAN_HELPER_
#define SE2EZ_PLAN_HELPER_

#include <ompl/base/ConstrainedSpaceInformation.h>
#include <ompl/base/Constraint.h>

#include <ompl/geometric/SimpleSetup.h>

#include <se2ez/core/class_forward.h>

namespace se2ez
{
    /** \cond IGNORE */
    SE2EZ_CLASS_FORWARD(Robot)
    SE2EZ_CLASS_FORWARD(State)
    /** \endcond */

    namespace plan
    {
        /** \cond IGNORE */
        SE2EZ_CLASS_FORWARD(StateSpace)
        /** \endcond */

        /** \cond IGNORE */
        SE2EZ_CLASS_FORWARD(EZPlans)
        /** \endcond */

        class EZPlans
        {
        public:
            EZPlans(const RobotPtr &robot);
            virtual ~EZPlans();

            template <typename T, typename... Args>
            std::shared_ptr<T> makePlanner(Args &&... args)
            {
                auto p = std::make_shared<T>(info, std::forward<Args>(args)...);
                p->setup();
                return p;
            }

            template <typename T, typename... Args>
            std::shared_ptr<T> setPlanner(Args &&... args)
            {
                auto planner = makePlanner<T>(std::forward<Args>(args)...);
                setup->setPlanner(planner);
                return planner;
            }

            virtual void initialize();
            virtual void updateValidityChecker();

            void createPlanners();

            /* \name State Functions
               \{ */
            bool setStart(const std::string &name);
            bool setGoal(const std::string &name);
            bool setStartGoal(const std::string &start, const std::string &goal);

            bool setStart(const Eigen::VectorXd &vec);
            bool setGoal(const Eigen::VectorXd &vec);
            bool setStartGoal(const Eigen::VectorXd &start, const Eigen::VectorXd &goal);

            bool setStart(const StatePtr &state);
            bool setGoal(const StatePtr &state);
            bool setStartGoal(const StatePtr &start, const StatePtr &goal);

            virtual bool postSetState(const ompl::base::State *state);
            /* \} */

            /* \name Path Functions
               \{ */
            std::vector<std::string> getPlanners();
            void setPlanner(const std::string &name);

            void postprocess(bool simplify, bool interpolate);

            std::vector<StatePtr> extractPath() const;
            /* \} */

            /* \name Utility Functions
               \{ */
            virtual StatePtr getState(ompl::base::State *state) const;
            virtual const StatePtr getStateConst(const ompl::base::State *state) const;
            /* \} */

            StateSpacePtr rspace;
            ompl::base::StateSpacePtr space;
            ompl::base::SpaceInformationPtr info;
            ompl::geometric::SimpleSetupPtr setup;

        protected:
            const RobotPtr robot_;
            std::map<std::string, ompl::base::PlannerPtr> planners_;
        };

        enum ConstraintType
        {
            PROJECTION,
            ATLAS,
            TANGENT
        };

        /** \cond IGNORE */
        SE2EZ_CLASS_FORWARD(EZPlansConstraint)
        /** \endcond */

        class EZPlansConstraint : public EZPlans
        {
        public:
            EZPlansConstraint(const RobotPtr &robot, const ompl::base::ConstraintPtr &constraint,
                              ConstraintType method);

            ~EZPlansConstraint() override;

            void initialize() override;
            void updateValidityChecker() override;
            bool postSetState(const ompl::base::State *state) override;

            ompl::base::ConstraintPtr constraint;
            const ConstraintType method;

            StatePtr getState(ompl::base::State *state) const override;
            const StatePtr getStateConst(const ompl::base::State *state) const override;

        protected:
            void anchor(const ompl::base::State *state);
            bool checkConstraint(const ompl::base::State *state) const;
        };
    }  // namespace plan
}  // namespace se2ez

#endif
