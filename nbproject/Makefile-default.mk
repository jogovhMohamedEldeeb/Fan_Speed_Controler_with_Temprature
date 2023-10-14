#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=app.c Mcal_layer/GPIO/hal_gpio.c Ecu_layer/LCD/ecu_lcd.c Mcal_layer/ADC/hal_adc.c Mcal_layer/Timer2/hal_timer2.c Ecu_layer/Motor/ecu_motor.c Mcal_layer/PWM/hal_pwm.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/app.p1 ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1 ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1 ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1 ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/app.p1.d ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1.d ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1.d ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1.d ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1.d ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/app.p1 ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1 ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1 ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1 ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1

# Source Files
SOURCEFILES=app.c Mcal_layer/GPIO/hal_gpio.c Ecu_layer/LCD/ecu_lcd.c Mcal_layer/ADC/hal_adc.c Mcal_layer/Timer2/hal_timer2.c Ecu_layer/Motor/ecu_motor.c Mcal_layer/PWM/hal_pwm.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1: Mcal_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/GPIO" 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 Mcal_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.d ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1: Ecu_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Ecu_layer/LCD" 
	@${RM} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1 Ecu_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.d ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1: Mcal_layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/ADC" 
	@${RM} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1 Mcal_layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.d ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1: Mcal_layer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/Timer2" 
	@${RM} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1 Mcal_layer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.d ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1: Ecu_layer/Motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Ecu_layer/Motor" 
	@${RM} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1 Ecu_layer/Motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.d ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1: Mcal_layer/PWM/hal_pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/PWM" 
	@${RM} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1 Mcal_layer/PWM/hal_pwm.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.d ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1: Mcal_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/GPIO" 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 Mcal_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.d ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1: Ecu_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Ecu_layer/LCD" 
	@${RM} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1 Ecu_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.d ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Ecu_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1: Mcal_layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/ADC" 
	@${RM} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1 Mcal_layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.d ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1: Mcal_layer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/Timer2" 
	@${RM} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1 Mcal_layer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.d ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1: Ecu_layer/Motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Ecu_layer/Motor" 
	@${RM} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1 Ecu_layer/Motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.d ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Ecu_layer/Motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1: Mcal_layer/PWM/hal_pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/PWM" 
	@${RM} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1 Mcal_layer/PWM/hal_pwm.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.d ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/PWM/hal_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Fan_speed_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
