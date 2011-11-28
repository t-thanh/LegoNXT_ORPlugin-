#include <openrave/plugin.h>
#include <boost/bind.hpp>
using namespace OpenRAVE;

class LegoNXT : public ModuleBase
{
public:
    LegoNXT(EnvironmentBasePtr penv, std::istream& ss) : ModuleBase(penv) {
        RegisterCommand("MyCommand",boost::bind(&LegoNXT::MyCommand,this,_1,_2),
                        "This is an example command");
		RegisterCommand("activate",boost::bind(&LegoNXT::activate,this,_1,_2),
                        "Activate");
    }
    virtual ~LegoNXT() {}
    
    bool MyCommand(std::ostream& sout, std::istream& sinput)
    {
        std::string input;
        sinput >> input;
        sout << "output";
        return true;
    }
 bool activate(std::ostream& sout, std::istream& sinput){
std::string input;
        sinput >> input;
        sout << "Accelerometer activated";
        return true;}
  void passivate(void){}

  short int getXAccel(void){}
  short int getYAccel(void){}
  short int getZAccel(void){}

  void getAccel(short int axes[3]){}
  void getAccel(short int &x,short int &y,short int &z){}

  inline bool isActivated(void) { return activated; }

 private:
  unsigned char port;
  bool activated;

  void fetchData(short int axes[3]);
};


// called to create a new plugin
InterfaceBasePtr CreateInterfaceValidated(InterfaceType type, const std::string& interfacename, std::istream& sinput, EnvironmentBasePtr penv)
{
    if( type == PT_Module && interfacename == "legonxt" ) {
        return InterfaceBasePtr(new LegoNXT(penv,sinput));
    }

    return InterfaceBasePtr();
}

// called to query available plugins
void GetPluginAttributesValidated(PLUGININFO& info)
{
info.interfacenames[PT_Module].push_back("LegoNXT");
    
}

// called before plugin is terminated
OPENRAVE_PLUGIN_API void DestroyPlugin()
{
}

