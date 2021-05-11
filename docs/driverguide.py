#   A driver has its structure as following:
#   ..../[driverdir]/<drivername>/main.py
#   inside the <drivername>/ directory Weathersens does not care about any other file than main.py

#
#   ALL the return values HAVE to be STRINGS, where the first letter contains the type:
    #|--------------------------------------------------------------|
    #|  N   no return value but ok                                  |
    #|  E   an error occured, error number following                |
    #|--------------------------------------------------------------|
    #|  #   type            example             value               |        
    #|--------------------------------------------------------------|
    #|  I   integer         "I5"                5                   |
    #|  F   float           "F1.3"              1.3                 |
    #|  D   double          "D2.1"              2.1                 |
    #|  S   string          "Shello"            hello               |
    #|  B   boolean         "B1"                true (0 for false)  |
    #|  C   char            "Ca"                a                   |
    #|--------------------------------------------------------------|
#    
#   functions resume() and pause() HAVE to return "N", else the execution will not continue


############
## OUTPUT ##
############

#	All logs have to contain flush=True, if this is not present the output will
#	appear at the very end of HomeNet. example:
#		print("Hello HomeNet!", flush=True)
#
#	These outputs do not use the default loging system, this is qeued to be implemented soon

#   Following functions HAVE to be present!

#   This function will get called before every getValue(...) call so the driver can prepare
#   resources such as connect to a port or load files...
def resume():
    return "N"


#   This function returns the contents of the value to Weathersens.
#
#   globalValueId       The valueId inside of Weathersens, this is unique
#   localValueId        The valueId inside this driver, this will directly match the position of
#                           the [driverlist] entry
#   workdir             This directory is reserved for this value, it can store everything it
#                           it needs in here
#                       WARNING: this directory will be located in a ramdisk!
def getValue(globalValueId, localValueId, workdir):
    return "N"


#   This function gets called after getValue(...) so the driver can store data and release resource
#   such as disconnecting from sockets...
def pause():
    return "N"
