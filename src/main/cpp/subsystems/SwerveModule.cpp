// Copyright (c) FRC Team 122. All Rights Reserved.

#include "subsystems/SwerveModule.hpp"
#include <cassert>

SwerveModule::SwerveModule(uint8_t module_id,
                           ctre::phoenix6::hardware::TalonFX &drive_motor,
                           ctre::phoenix6::hardware::TalonFX &steer_motor,
                           ctre::phoenix6::hardware::CANcoder &steer_encoder,
                           double angle_offset,
                           double drive_gear_ratio,
                        double steer_gear_ratio,
                        double wheel_radius) : m_id(module_id),
                                                      m_driveGearRatio(drive_gear_ratio),
                                                      m_wheelRadius(wheel_radius),
                                                      m_steerGearRatio(steer_gear_ratio),
                                                      m_angleOffset(angle_offset),
                                                      m_driveMotor(drive_motor),
                                                      m_steerMotor(steer_motor),
                                                      m_steerEncoder(steer_encoder)
{
    // Ensure swerve module definitions are valid
    assert(this->m_driveGearRatio != 0 && this->m_steerGearRatio != 0 && this->m_wheelRadius > 0);
}

/// Public Methods

frc::SwerveModuleState SwerveModule::GetCurrentState()
{
    frc::SwerveModuleState ret_val {};
    // Get the current drive motor speed and direction

    // Get the encoder direction

    // Construct and return Module State object
    return ret_val;
}

void SwerveModule::SetDesiredState(frc::SwerveModuleState desiredState)
{
    // Save the new state as the new desired state
    this->m_desiredState = desiredState;
}

void SwerveModule::SetEncoderZero()
{
    // Zero out the encoder
}

void SwerveModule::Reset()
{
    // Set desired state speed to 0
}

/// Private Methods
