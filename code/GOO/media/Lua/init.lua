LogMessage("loading init.lua..")
DIR= "..\\..\\media\\LUA\\"
LogMessage(DIR)
--celldefs= string.format("%s%s",DIR,"celldefinitions\\celldefinitions.lua")
--LogMessage(celldefs)
--LogMessage("hallo")
RunScript("..\\..\\media\\LUA\\celldefinitions\\celldefinitions.lua")

--load cell systems
RunScript("..\\..\\media\\LUA\\systems\\system_definitions.lua")


--register event handler







