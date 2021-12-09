#include "homenet.h"

void HomeNet::sync(){
	FUN();

	LOGI("Syncing values...");

	try{
		this->_drivers->sync();
		hnvalue_t value;
		
		{//Clean up history if needed
			if (this->_syncs_for_cleanup != 0){
				if (this->_syncs_since_cleanup >= this->_syncs_for_cleanup){
					this->cleanupHistory();
					this->_syncs_since_cleanup = 0;
				}else
					this->_syncs_since_cleanup++;

				LOGI(	"Syncs until next history cleanup: " + 
						std::to_string(this->_syncs_for_cleanup - this->_syncs_since_cleanup));
			}
		}
		
	}catch(...){
		LOGE("Fatal exception during syncing!");
	}
}
