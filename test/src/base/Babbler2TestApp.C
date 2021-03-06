//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "Babbler2TestApp.h"
#include "Babbler2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
Babbler2TestApp::validParams()
{
  InputParameters params = Babbler2App::validParams();
  return params;
}

Babbler2TestApp::Babbler2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  Babbler2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

Babbler2TestApp::~Babbler2TestApp() {}

void
Babbler2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  Babbler2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"Babbler2TestApp"});
    Registry::registerActionsTo(af, {"Babbler2TestApp"});
  }
}

void
Babbler2TestApp::registerApps()
{
  registerApp(Babbler2App);
  registerApp(Babbler2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
Babbler2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Babbler2TestApp::registerAll(f, af, s);
}
extern "C" void
Babbler2TestApp__registerApps()
{
  Babbler2TestApp::registerApps();
}
