#pragma once
// updated 1.2.5b15
class Minecraft;
class Player;
class CommandOrigin {
public:
	CommandOrigin();
	virtual ~CommandOrigin();
};
class DedicatedServerCommandOrigin : public CommandOrigin {
public:
	DedicatedServerCommandOrigin(std::string const&, Minecraft&);
	virtual ~DedicatedServerCommandOrigin();
	char filler[32-4]; // 4 from DedicatedServerCommandOrigin::clone()
};
static_assert(sizeof(DedicatedServerCommandOrigin) == 32, "dedicated server command size");

class DevConsoleCommandOrigin : public CommandOrigin {
public:
	DevConsoleCommandOrigin(Player&);
	virtual ~DevConsoleCommandOrigin();
	char filler[200-4]; // 4 from DevConsoleCommandOrigin::clone()
};
static_assert(sizeof(DevConsoleCommandOrigin) == 200, "dev console command size");

class CommandVersion {
public:
	static int CurrentVersion;
};