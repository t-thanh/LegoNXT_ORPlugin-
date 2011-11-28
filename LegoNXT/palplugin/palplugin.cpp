#include <openrave/plugin.h>
#include <boost/bind.hpp>
using namespace OpenRAVE;

class PalPhysics : public PhysicsEngineBase
{
public:
    PalPhysics(EnvironmentBasePtr penv, std::istream& ss) : PhysicsEngineBase(penv) {
        RegisterCommand("MyCommand",boost::bind(&PalPhysics::MyCommand,this,_1,_2),
                        "This is an example command");
    }
    virtual ~PalPhysics() {}
    
    bool MyCommand(std::ostream& sout, std::istream& sinput)
    {
        std::string input;
        sinput >> input;
        sout << "output";
        return true;
    }
};


// called to create a new plugin
InterfaceBasePtr CreateInterfaceValidated(InterfaceType type, const std::string& interfacename, std::istream& sinput, EnvironmentBasePtr penv)
{
    if( type == PT_PhysicsEngine && interfacename == "palphysics" ) {
        return InterfaceBasePtr(new PalPhysics(penv,sinput));
    }

    return InterfaceBasePtr();
}

// called to query available plugins
void GetPluginAttributesValidated(PLUGININFO& info)
{
info.interfacenames[PT_PhysicsEngine].push_back("PalPhysics");
    
}

// called before plugin is terminated
OPENRAVE_PLUGIN_API void DestroyPlugin()
{
}

