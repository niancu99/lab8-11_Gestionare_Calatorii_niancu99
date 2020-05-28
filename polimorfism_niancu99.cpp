// polimorfism_niancu99.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestRepoFile.h"
#include "Utilizator.h"
#include "TestCalatorie.h"
#include "TestValidatorCalatorie.h"
#include "TestService.h"
#include "UI.h"

int main()
{

    TestValidatorCalatorie testval;
    testval.testAll();
    TestService testservice;
    testservice.testAll();

    RepoCustom<Utilizator> RepoUtilizator;
    RepoUtilizator.setf_name("Useri.txt");
    RepoFile* repofile = new RepoTXT("Calatorii.txt");
    Service serv(RepoUtilizator, repofile);
    UI ui(serv);
    ui.run();
    return 0;
}

