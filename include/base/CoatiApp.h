#ifndef COATIAPP_H
#define COATIAPP_H

#include "MooseApp.h"

class CoatiApp;

template<>
InputParameters validParams<CoatiApp>();

class CoatiApp : public MooseApp
{
public:
  CoatiApp(InputParameters parameters);
  virtual ~CoatiApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* COATIAPP_H */
