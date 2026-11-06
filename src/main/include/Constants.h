// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
#include <string>
#include <units/length.h>
#include <units/velocity.h>
#include <units/angular_velocity.h>

namespace DriveConstants {
    inline constexpr units::meters_per_second_t k_maxTranslationalVelocity{4};
    inline constexpr units::radians_per_second_t k_maxRotationalVelocity{6};
} // namespace DriveConstants

namespace PhysicalConstants {
    inline constexpr units::meter_t k_swerveDriveWheelRadius{0.25};
} // namespace PhysicalConstants

namespace CANIDValues {
    const int k_FrontLeftDriveMotorID = 10;
    const int k_FrontLeftTurnMotorID = 11;
    const int k_FrontLeftEncoderID = 12;

    const int k_FrontRightDriveMotorID = 20;
    const int k_FrontRightTurnMotorID = 21;
    const int k_FrontRightEncoderID = 22;

    const int k_BackLeftDriveMotorID = 30;
    const int k_BackLeftTurnMotorID = 31;
    const int k_BackLeftEncoderID = 32;

    const int k_BackRightDriveMotorID = 40;
    const int k_BackRightTurnMotorID = 41;
    const int k_BackRightEncoderID = 42;
} // namespace CANIDValues

namespace MotorConstants {
    namespace SwerveModule {
        namespace DriveMotor {
            // Describe the initial values of the PID loop
            const double k_P = 1.0;
            const double k_I = 0.0;
            const double k_D = 0.0;
            const double k_S = 0.0;
            const double k_V = 0.0;
            const double k_A = 0.0;

            // The names of the preferences that will store drive motor PID
            inline constexpr std::string_view k_PPrefKey {"SwerveDriveConst_P"};
            inline constexpr std::string_view k_IPrefKey {"SwerveDriveConst_I"};
            inline constexpr std::string_view k_DPrefKey {"SwerveDriveConst_D"};
            inline constexpr std::string_view k_SPrefKey {"SwerveDriveConst_S"};
            inline constexpr std::string_view k_VPrefKey {"SwerveDriveConst_V"};
            inline constexpr std::string_view k_APrefKey {"SwerveDriveConst_A"};
        } // namespace DriveMotor

        namespace SteerMotor {
            // Describe the initial values of the PID loop
            const double k_P = 1.0;
            const double k_I = 0.0;
            const double k_D = 0.0;
            const double k_S = 0.0;
            const double k_V = 0.0;
            const double k_A = 0.0;

            // The names of the preferences that will store steer motor PID
            inline constexpr std::string_view k_PPrefKey {"SwerveSteerConst_P"};
            inline constexpr std::string_view k_IPrefKey {"SwerveSteerConst_I"};
            inline constexpr std::string_view k_DPrefKey {"SwerveSteerConst_D"};
            inline constexpr std::string_view k_SPrefKey {"SwerveSteerConst_S"};
            inline constexpr std::string_view k_VPrefKey {"SwerveSteerConst_V"};
            inline constexpr std::string_view k_APrefKey {"SwerveSteerConst_A"};
        } // namespace SteerMotor
    } // namespace SwerveModule
} // namespace MotorConstants
