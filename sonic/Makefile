CXX = gcc
CXXFLAGS = -g
LDLIBS = -lallegro -lallegro_image

OBJ = ssprite.cpp pelota.cpp prota.cpp
DEPS = pelota.h prota.h

bouncy: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)


%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	$(RM) *.o *~

