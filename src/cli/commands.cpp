#include "../../include/cli/commands.hh"
#include "../../include/user/users_manager.hh"
#include "../../include/user/user.hh"
#include "../../include/challenge/challenges_manager.hh"
#include <stdlib.h>
#include <iostream>


ICommand::~ICommand() {}

Register::Register(UsersManager* usersManager) {
    this->usersManager = usersManager;
}

bool isNumber(char* arg) {
    short count = 0;
    while(arg[count]) {
        if('0' > arg[count] || arg[count] > '9') {
            return false;
        }
        count++;
    }
    return true;
}

void Register::execute(char args[256][256]) {
    char* name = args[0];

    if(isNumber(args[1])) {
        short age = atoi(args[1]);

        if(!strcmp(args[2], "")) {
            this->usersManager->createUser(name, age);
        } else {
            char* email = args[2];
            this->usersManager->createUser(name, age, email);
        }

    } else {
        char* email = args[1];
        this->usersManager->createUser(name, email);
    }

    std::cout << "Successfully created user" << "\n";
}

const char* Register::getName() {
    return "registration";
}

CreateChallenge::CreateChallenge(ChallengesManager* challengesManager, UsersManager* usersManager) 
    :challengesManager(challengesManager), usersManager(usersManager) {}

void CreateChallenge::execute(char args[256][256]) {
    User* userChallenger = this->usersManager->getUserByName(args[0]);

    User* challengedUsers[256];

    short args_iterator = 2;
    short challenged_users_iterator = 0;

    while(strcmp(args[args_iterator], "")) {
        challengedUsers[challenged_users_iterator] = this->usersManager->getUserByName(args[args_iterator]);
        args_iterator++;
        challenged_users_iterator++;
    }

    Challenge* challenge = this->challengesManager->getChallengeByName(args[1]);

    if(challenge == nullptr) {
        challenge = this->challengesManager->createChallenge(args[1]);
    }

    for(unsigned i = 0; i < challenged_users_iterator-1; i++) {
        challengedUsers[i]->addChallenge(challenge);
    }

}

const char* CreateChallenge::getName() {
    return "challenge";
}

FinishChallenge::FinishChallenge(ChallengesManager* challengesManager, UsersManager* usersManager)
    : challengesManager(challengesManager), usersManager(usersManager) {}

void FinishChallenge::execute(char args[256][256]) {
    char* challenge_name = args[0];
    short user_id = args[1];
    double rating = atof(args[2]);

    //Remove challenge from the Users challenge list
    //Update the Challenge's rating
}

const char* FinishChallenge::getName() {
    return "finish";
}

ProfileInfo::ProfileInfo(UsersManager* usersManager) {
    this->usersManager = usersManager;
}

void ProfileInfo::execute(char args[256][256]) {
    User* user = this->usersManager->getUserByName(args[0]);
    user->print();
}

const char* ProfileInfo::getName() {
    return "profile_info";
}

ListBy::ListBy(ChallengesManager* challengesManager): challengesManager(challengesManager) {}

void ListBy::execute(char args[256][256]) {
    char* sortBy = args[0];
    
    short challengesCount = this->challengesManager->getChallengesCount();
    Challenge** challenges = this->challengesManager->getAllChallenges();

    for(unsigned i = 0; i < challengesCount; i++) {
        challenges[i]->print();
    }
}

const char* ListBy::getName() {
    return "list_by";
}
