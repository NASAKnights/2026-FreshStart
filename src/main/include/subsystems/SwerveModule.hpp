// Copyright (c) FRC Team 122. All Rights Reserved.

#pragma once

#include <ctre/phoenix6/CANcoder.hpp>
#include <ctre/phoenix6/TalonFX.hpp>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/simulation/SimDeviceSim.h>
#include <frc/DataLogManager.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <wpi/DataLog.h>

#include "Constants.h"

class SwerveModule
{
public:
  SwerveModule(int driveMotorId, int steerMotorId, int steerEncoderId,
               frc::Rotation2d angleOffset, ctre::phoenix6::CANBus _canBus);

  frc::SwerveModuleState GetCurrentState();
  frc::SwerveModulePosition GetPosition();
  void SetDesiredState(frc::SwerveModuleState desiredState);
  void ResetDriveEncoders();
  void InitEncoder(int encoderID);
  frc::Rotation2d GetRotation();
  frc::Rotation2d GetAbsoluteRotation();
  void SetOffset(frc::Rotation2d);
  void Reset();

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  int m_id;

  ctre::phoenix6::hardware::TalonFX m_driveMotor;
  ctre::phoenix6::hardware::TalonFX m_steerMotor;
  ctre::phoenix6::hardware::CANcoder m_steerEncoder;

  frc::Rotation2d m_angleOffset;

  // simulation fields
  frc::Timer m_simTimer;

  frc::sim::SimDeviceSim m_driveSim;
  frc::sim::SimDeviceSim m_steerSim;

  double m_driveSimVelocity;
  double m_driveSimPosition;
  double m_steerSimPosition;

  wpi::log::DoubleLogEntry m_driveMotorCurrentLog;
  wpi::log::DoubleLogEntry m_driveMotorVoltageLog;
  wpi::log::DoubleLogEntry m_steerMotorCurrentLog;
  wpi::log::DoubleLogEntry m_steerMotorVoltageLog;
};
