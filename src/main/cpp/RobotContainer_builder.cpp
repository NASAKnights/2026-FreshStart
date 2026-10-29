// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

// Object Factories
#include "init/SwerveDrive_Init.hpp"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  this->m_swerve_drive = GetSwerveDrive();

  // Configure the button bindings
  ConfigureBindings();
}
