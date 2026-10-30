// Copyright (c) FRC Team 122. All Rights Reserved.

#include "subsystems/SwerveModule.hpp"

SwerveModule::SwerveModule(uint8_t module_id,
                           ctre::phoenix6::hardware::TalonFX *drive_motor,
                           ctre::phoenix6::hardware::TalonFX *steer_motor,
                           ctre::phoenix6::hardware::CANcoder *steer_encoder,
                           double angle_offset) : m_id(module_id),
                                                  m_angleOffset(angle_offset),
                                                  m_driveMotor(drive_motor),
                                                  m_steerMotor(steer_motor),
                                                  m_steerEncoder(steer_encoder)
{
}
