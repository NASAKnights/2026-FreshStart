// Copyright (c) FRC Team 122. All Rights Reserved.

#pragma once

#include <ctre/phoenix6/CANcoder.hpp>
#include <ctre/phoenix6/TalonFX.hpp>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/simulation/SimDeviceSim.h>
#include <frc/DataLogManager.h>
#include <wpi/DataLog.h>
#include <ctre/phoenix6/CANcoder.hpp>
#include <ctre/phoenix6/TalonFX.hpp>

#include "Constants.h"

/**
 * @brief Outlines the structure for a single Swerve Module
 *
 * It is one component of a swerve drive. Consists of an absolute encoder
 * attached to the shaft of the wheel, a motor that provides the wheel power (drive motor),
 * and a motor that changes the direction the wheel is pointing (steer motor)
 */
class SwerveModule
{
public:
  /**
   * @brief Main Constructor
   *
   * @param module_id The ID of the Swerve Module. Should be unique among all swerve modules
   */
  SwerveModule(uint8_t module_id,
               ctre::phoenix6::hardware::TalonFX &drive_motor,
               ctre::phoenix6::hardware::TalonFX &steer_motor,
               ctre::phoenix6::hardware::CANcoder &steer_encoder,
               double angle_offset,
               double drive_gear_ratio,
               double steer_gear_ratio,
               double wheel_radius);

  frc::SwerveModuleState GetCurrentState();
  void SetDesiredState(frc::SwerveModuleState desiredState);
  void SetEncoderZero();
  void Reset();
  void SwerveModuleThread();

private:
  /// @brief The ID of the module. Should be unique among all modules
  uint8_t m_id;

  /// @brief The gear ratio between the drive motor and the wheel.
  double m_driveGearRatio;
  double m_wheelRadius;
  double m_steerGearRatio;

  double m_angleOffset;

  frc::SwerveModuleState m_desiredState;

  ctre::phoenix6::hardware::TalonFX &m_driveMotor;
  ctre::phoenix6::hardware::TalonFX &m_steerMotor;
  ctre::phoenix6::hardware::CANcoder &m_steerEncoder;

  wpi::log::DoubleLogEntry m_driveMotorCurrentLog;
  wpi::log::DoubleLogEntry m_driveMotorVoltageLog;
  wpi::log::DoubleLogEntry m_steerMotorCurrentLog;
  wpi::log::DoubleLogEntry m_steerMotorVoltageLog;
};
