#include "CoatiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<CoatiApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

CoatiApp::CoatiApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CoatiApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CoatiApp::associateSyntax(_syntax, _action_factory);
}

CoatiApp::~CoatiApp()
{
}

// External entry point for dynamic application loading
extern "C" void CoatiApp__registerApps() { CoatiApp::registerApps(); }
void
CoatiApp::registerApps()
{
  registerApp(CoatiApp);
}

// External entry point for dynamic object registration
extern "C" void CoatiApp__registerObjects(Factory & factory) { CoatiApp::registerObjects(factory); }
void
CoatiApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CoatiApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CoatiApp::associateSyntax(syntax, action_factory); }
void
CoatiApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
