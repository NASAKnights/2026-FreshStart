/**
 * @brief Declares the Swerve Drive class and interface
 * 
 * Includes all Swerve Modules, and the command interface of how to control the drivebase
 */

 // Copyright (c) FRC Team 122. All Rights Reserved.

#pragma once

#include <ctre/phoenix6/Pigeon2.hpp>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/controller/PIDController.h>
#include <networktables/NetworkTableInstance.h>

#include "Constants.h"
#include "SwerveModule.hpp"

class SwerveDrive  : public frc2::SubsystemBase
{
public:
  SwerveDrive(ctre::phoenix6::CANBus canBus);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called perodically by the scheduler when simulation runs.
   */
  void SimulationPeriodic() override;

  void Drive(frc::ChassisSpeeds);

  frc::Rotation2d GetHeading();
  void ResetHeading();
  void ResetDriveEncoders();
  void EnableDrive();
  void DisableDrive();

  std::array<frc::SwerveModulePosition, 4> GetModulePositions();

  void ResetPose(frc::Pose2d position);

  frc::Pose2d GetPose();

  void UpdateOdometry();
  frc::ChassisSpeeds getRobotRelativeSpeeds();

  void InitializePID();
  void SetReference(frc::Pose2d);
  void Strafe(frc::ChassisSpeeds speeds, double angle);

  void PublishOdometry(frc::Pose2d);
  void PrintNetworkTablseValues();
  void PeriodicShuffleboard();
  void ShuffleboardInit();

private:
  units::meters_per_second_t m_currentMaxSpeed = 4.0_mps;

  ctre::phoenix6::CANBus m_canBus;
  ctre::phoenix6::hardware::Pigeon2 m_pigeon;

  std::array<SwerveModule, 4> modules;
  frc::SwerveDriveKinematics<4U> kSwerveKinematics;

  frc::ChassisSpeeds speeds;
  frc::PIDController pidX;
  frc::PIDController pidY;
  frc::PIDController pidRot;

  nt::NetworkTableInstance networkTableInst;

  std::shared_ptr<nt::NetworkTable> poseTable;

  /* Simulation */
  frc::Timer m_simTimer;
  ctre::phoenix6::sim::Pigeon2SimState m_pigeonSim;
  frc::Rotation2d m_simAngle;
};
