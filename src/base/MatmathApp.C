#include "MatmathApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<MatmathApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MatmathApp::MatmathApp(InputParameters parameters) : MooseApp(parameters)
{
  MatmathApp::registerAll(_factory, _action_factory, _syntax);
}

MatmathApp::~MatmathApp() {}

void
MatmathApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MatmathApp"});
  Registry::registerActionsTo(af, {"MatmathApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MatmathApp::registerApps()
{
  registerApp(MatmathApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MatmathApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MatmathApp::registerAll(f, af, s);
}
extern "C" void
MatmathApp__registerApps()
{
  MatmathApp::registerApps();
}
