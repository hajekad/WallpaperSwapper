# Define the compiler and its flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall --pedantic

# Define the directory where the source files are located
SRCDIR = src

# Define the directory where the object files will be created
OBJDIR = obj

# Define the name of the final output
OUTPUT = WaSp

# Find all source files in subdirectories and create a list of corresponding object files
SOURCES = $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# .PHONY: install
# install:
# 	@echo "Checking for libcurl..."
# 	@if ! pkg-config --exists libcurl; then \
# 		echo "libcurl not found, installing..."; \
# 		git clone https://github.com/curl/curl.git; \
# 		cd curl; \
# 		./configure --with-openssl; \
# 		make; \
# 		sudo make install; \
# 	fi

# Rule to compile all .cpp files to .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link all object files to create the final output
$(OUTPUT): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lcurl

# Rule to clean up all object files and the final output
clean:
	rm -rf $(OBJDIR)/*.o $(OUTPUT)
	rm -rf curl
	rm assets/*.jpg
