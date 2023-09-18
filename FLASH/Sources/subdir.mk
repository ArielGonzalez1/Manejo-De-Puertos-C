################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Man_Pue.c" \

C_SRCS += \
../Sources/Man_Pue.c \

OBJS += \
./Sources/Man_Pue_c.obj \

OBJS_QUOTED += \
"./Sources/Man_Pue_c.obj" \

C_DEPS += \
./Sources/Man_Pue_c.d \

C_DEPS_QUOTED += \
"./Sources/Man_Pue_c.d" \

OBJS_OS_FORMAT += \
./Sources/Man_Pue_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Man_Pue_c.obj: ../Sources/Man_Pue.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Man_Pue.args" -ObjN="Sources/Man_Pue_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


