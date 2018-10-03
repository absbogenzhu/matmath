//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MatmathTestApp.h"
#include "MatmathApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<MatmathTestApp>()
{
  InputParameters params = validParams<MatmathApp>();
  return params;
}

MatmathTestApp::MatmathTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MatmathTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MatmathTestApp::~MatmathTestApp() {}

void
MatmathTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MatmathApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MatmathTestApp"});
    Registry::registerActionsTo(af, {"MatmathTestApp"});
  }
}

void
MatmathTestApp::registerApps()
{
  registerApp(MatmathApp);
  registerApp(MatmathTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MatmathTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MatmathTestApp::registerAll(f, af, s);
}
extern "C" void
MatmathTestApp__registerApps()
{
  MatmathTestApp::registerApps();
}
