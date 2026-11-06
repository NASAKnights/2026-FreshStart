/**
 * Implements the builder of the swerve drive object
 */

#include "Constants.h"
#include "init/SwerveDrive_Init.hpp"
#include <ctre/phoenix6/core/CoreTalonFX.hpp>
#include <frc/Preferences.h>



static ctre::phoenix6::configs::Slot0Configs getDriveMotorSlot0Configs();
static ctre::phoenix6::configs::Slot0Configs getSteerMotorSlot0Configs();

SwerveDrive *GetSwerveDrive()
{
    // Construct the Drive Motor object
    ctre::phoenix6::configs::TalonFXConfiguration driveConfig{};
    ctre::phoenix6::configs::TalonFXConfiguration steerConfig{};

    // Get the motor Slot 0 configs
    driveConfig.Slot0 = getDriveMotorSlot0Configs();
    steerConfig.Slot0 = getSteerMotorSlot0Configs();

    return NULL;
}

ctre::phoenix6::configs::Slot0Configs getDriveMotorSlot0Configs()
{
    ctre::phoenix6::configs::Slot0Configs slot_config{};

    // Init the preference if it does not already exist.
    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::DriveMotor::k_PPrefKey,
        MotorConstants::SwerveModule::DriveMotor::k_P);

    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::DriveMotor::k_IPrefKey,
        MotorConstants::SwerveModule::DriveMotor::k_I);

    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::DriveMotor::k_DPrefKey,
        MotorConstants::SwerveModule::DriveMotor::k_D);

    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::DriveMotor::k_SPrefKey,
        MotorConstants::SwerveModule::DriveMotor::k_S);

    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::DriveMotor::k_VPrefKey,
        MotorConstants::SwerveModule::DriveMotor::k_V);

    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::DriveMotor::k_APrefKey,
        MotorConstants::SwerveModule::DriveMotor::k_A);

    // Save the preference to the config
    slot_config.kP = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::DriveMotor::k_PPrefKey);

    slot_config.kI = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::DriveMotor::k_IPrefKey);

    slot_config.kD = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::DriveMotor::k_DPrefKey);

    slot_config.kS = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::DriveMotor::k_SPrefKey);

    slot_config.kV = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::DriveMotor::k_VPrefKey);

    slot_config.kA = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::DriveMotor::k_APrefKey);

    return slot_config;
}

ctre::phoenix6::configs::Slot0Configs getSteerMotorSlot0Configs()
{
    ctre::phoenix6::configs::Slot0Configs slot_config{};

    // Init the preference if it does not already exist.
    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::SteerMotor::k_PPrefKey,
        MotorConstants::SwerveModule::SteerMotor::k_P);

    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::SteerMotor::k_IPrefKey,
        MotorConstants::SwerveModule::SteerMotor::k_I);

    frc::Preferences::InitDouble(
        MotorConstants::SwerveModule::SteerMotor::k_DPrefKey,
        MotorConstants::SwerveModule::SteerMotor::k_D);

    // Save the preference to the config
    slot_config.kP = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::SteerMotor::k_PPrefKey);

    slot_config.kI = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::SteerMotor::k_IPrefKey);

    slot_config.kD = frc::Preferences::GetDouble(
        MotorConstants::SwerveModule::SteerMotor::k_DPrefKey);

    return slot_config;
}
