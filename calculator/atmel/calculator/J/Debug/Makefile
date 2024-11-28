################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../lcd


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../lcd/LCD-routines.c \
../main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
lcd/LCD-routines.o \
main.o

OBJS_AS_ARGS +=  \
lcd/LCD-routines.o \
main.o

C_DEPS +=  \
lcd/LCD-routines.d \
main.d

C_DEPS_AS_ARGS +=  \
lcd/LCD-routines.d \
main.d

OUTPUT_FILE_PATH +=J.elf

OUTPUT_FILE_PATH_AS_ARGS +=J.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler





lcd/%.o: ../lcd/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Users\Apple\Desktop\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "C:\Users\Apple\Desktop\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Users\Apple\Desktop\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "C:\Users\Apple\Desktop\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="J.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32a -B "C:\Users\Apple\Desktop\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a"  
	@echo Finished building target: $@
	"C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "J.elf" "J.hex"
	"C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "J.elf" "J.eep" || exit 0
	"C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "J.elf" > "J.lss"
	"C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "J.elf" "J.srec"
	"C:\Users\Apple\Desktop\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "J.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "J.elf" "J.a" "J.hex" "J.lss" "J.eep" "J.map" "J.srec" "J.usersignatures"
	