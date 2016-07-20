PROJECTNAME=JLib

TARGET=$(PROJECTNAME)_STATIC
XBUILD=xcodebuild
XBUILD_FLAGS=-Wl,-map,output.map
PROJECT_ROOT=../CMakeGen/Xcode/$(PROJECTNAME)
BINPATH=../bin
SOURCE=$(PROJECT_ROOT)
PROJECT=$(PROJECT_ROOT)/$(PROJECTNAME).xcodeproj
SDK=-sdk iphoneos7.0
SDKSIM=-sdk iphonesimulator7.0
NAMESPACE=$(PROJECTNAME)

ARCHSIM = i386 x86_64
ARCHOS = armv7 armv7s arm64

all: BuildAll

ARCHSIMLOOP: 
	for prefix in $(ARCHSIM) ; do \
		echo $$prefix ; \
		$(XBUILD) -project $(PROJECT) -target $(TARGET) $(SDKSIM) -arch $$prefix -configuration Release clean build ; \
		mv $(BINPATH)/Release/lib$(TARGET).a $(BINPATH)/Release/lib$(TARGET)-$$prefix.a ; \
		$(XBUILD) -project $(PROJECT) -target $(TARGET) $(SDKSIM) -arch $$prefix -configuration Debug clean build ; \
		mv $(BINPATH)/Debug/lib$(TARGET).a $(BINPATH)/Debug/lib$(TARGET)-$$prefix-Debug.a ; \
	done

ARCHOSLOOP: 
	for prefix in $(ARCHOS) ; do \
		echo $$prefix ; \
		$(XBUILD) -project $(PROJECT) -target $(TARGET) $(SDK) -arch $$prefix -configuration Release clean build ; \
		mv $(BINPATH)/Release/lib$(TARGET).a $(BINPATH)/Release/lib$(TARGET)-$$prefix.a ; \
		$(XBUILD) -project $(PROJECT) -target $(TARGET) $(SDK) -arch $$prefix -configuration Debug clean build ; \
		mv $(BINPATH)/Debug/lib$(TARGET).a $(BINPATH)/Debug/lib$(TARGET)-$$prefix-Debug.a ; \
	done

BuildAll: ARCHSIMLOOP ARCHOSLOOP
	xcrun -sdk iphoneos lipo -create -output $(BINPATH)/Release/lib$(TARGET).a $(BINPATH)/Release/lib$(TARGET)-i386.a $(BINPATH)/Release/lib$(TARGET)-x86_64.a $(BINPATH)/Release/lib$(TARGET)-armv7.a $(BINPATH)/Release/lib$(TARGET)-armv7s.a $(BINPATH)/Release/lib$(TARGET)-arm64.a
	xcrun -sdk iphoneos lipo -create -output $(BINPATH)/Debug/lib$(TARGET)-Debug.a $(BINPATH)/Debug/lib$(TARGET)-i386-Debug.a $(BINPATH)/Debug/lib$(TARGET)-x86_64-Debug.a $(BINPATH)/Debug/lib$(TARGET)-armv7-Debug.a $(BINPATH)/Debug/lib$(TARGET)-armv7s-Debug.a $(BINPATH)/Debug/lib$(TARGET)-arm64-Debug.a

clean:
	-rm -rf *.a *.dll build
