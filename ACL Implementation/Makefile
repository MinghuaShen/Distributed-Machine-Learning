SHELL = /bin/sh

objects = neon_shuffle3.o opWrapper.o 
Path = /root/Project/NeurIoT
ACLPath = /root/Git/ComputeLibrary-19.08
Link = -c -Wno-deprecated-declarations -Wall -DARCH_ARM -Wextra -Wno-unused-parameter \
	-pedantic -Wdisabled-optimization -Wformat=2 -Winit-self -Wstrict-overflow=2 -Wswitch-default \
	-fpermissive -std=gnu++11 -Wno-vla -Woverloaded-virtual -Wctor-dtor-privacy -Wsign-promo -Weffc++ -Wno-format-nonliteral \
	-Wno-overlength-strings -Wno-strict-overflow -Wlogical-op -Wnoexcept -Wstrict-null-sentinel -Wno-redundant-move -march=armv8-a \
	-Werror -O3 -D_GLIBCXX_USE_NANOSLEEP -DARM_COMPUTE_CPP_SCHEDULER=1 -DARM_COMPUTE_AARCH64_V8A -DNO_DOT_IN_TOOLCHAIN \
	-Iinclude -I /root/Git/ComputeLibrary-19.08/include -I ${ACLPath}

neon_shuffle3 : ${objects}
	g++ -o $@ $^ ${ACLPath}/build/utils/Utils.o ${ACLPath}/build/utils/GraphUtils.o -lpthread -L${ACLPath}/build -L. -lpthread -larm_compute_graph -larm_compute -larm_compute_core

	
neon_shuffle3.o : neon_shuffle3.cpp 
	g++ -o $@ -c $< ${Link} 
	
opWrapper.o : opWrapper.cpp
	g++ -o $@ -c $< ${Link} 
	
.PHONY : clean
clean :
	-rm neon_shuffle3 $(objects)
	
	