#include "Babbler2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
Babbler2App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

Babbler2App::Babbler2App(InputParameters parameters) : MooseApp(parameters)
{
  Babbler2App::registerAll(_factory, _action_factory, _syntax);
}

Babbler2App::~Babbler2App() {}

void
Babbler2App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"Babbler2App"});
  Registry::registerActionsTo(af, {"Babbler2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
Babbler2App::registerApps()
{
  registerApp(Babbler2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
Babbler2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Babbler2App::registerAll(f, af, s);
}
extern "C" void
Babbler2App__registerApps()
{
  Babbler2App::registerApps();
}
