//
//  AnalyticsConstants.h
//  CBTiCoach
//
//  Created by Josh Ault on 10/29/14.
//  Copyright (c) 2014 Vertical Product Development. All rights reserved.
//

#define kContentHTMLURLInviteCodeScreen @"inviteCode.html"

#define kAnalyticsTimestampFormat @"%ld-%02ld-%02ld'T'%02ld:%02ld:%02ld"

#define kEventInviteCodeConfirmed @"Invite Code Confirmed"

/* Navigation Events */

#define kEventTabBarItemSelected @"TAB_BAR_ITEM_SELECTED"

// ? -> Home
#define kEventNavHome @"Home"

// ? -> Help
#define kEventNavHelp @"Help"

// ? -> Back
#define kEventNavBack @"Back"

// Home -> Settings
#define kEventNavHomeToSettings @"Settings"
#define kWorkingWithProvider @"ISI Provider"
#define kProvideAnonymousUsage @"Anonymous Usage"

// Settings -> Export
#define kEventNavSettingsToExport @"Export"
#define kExportAssessments @"Assessments"
#define kExportSleepDiaries @"Sleep"
#define kExportCompleted @"Export Completed"

// Home -> About
#define kEventNavHomeToAbout @"About"
#define kEventNavAboutCBTiCoach @"About CBT-I Coach"
#define kEventNavAboutProjectTeamSMEs @"Project Team and SMEs"
#define kEventNavAboutProjectPartners @"Project Partners"
#define kEventNavAboutAdditionalResources @"Additional Resources"

// Reminders
#define kEventReminders @"Reminders"
#define kRemindersSleepDiaryEntry @"Sleep Diary Entry Reminder"
#define kRemindersWindDownTime @"Wind Down Reminder"
#define kRemindersPrescribedBedTime @"Bed Time Reminder"
#define kRemindersPrescribedWakeTime @"Wake Reminder"
#define kRemindersUpdateSleepPrescription @"Rx Update Reminder"
#define kRemindersTakeAssessment @"Take Assessment Reminder"
#define kRemindersStopCaffeine @"Stop Caffeine Reminder"
#define kRemindersWorryTime @"Worry Time Reminder"
#define kResetRemindersCompleted @"Reset All Reminders"

// Learn
#define kEventLearn @"Learn"
#define kEventNavLearnSleep101 @"Sleep 101"
#define kEventNavLearnSleep101WhatIsCBTi @"What is CBT-i?"
#define kEventNavLearnSleep101WhyDoWeSleep @"Why Do We Sleep?"
#define kEventNavLearnSleep101TheStagesOfSleep @"The Stages of Sleep?"
#define kEventNavLearnSleep101SleepRegulators @"Sleep Regulators"
#define kEventNavLearnSleep101SleepinessVsTiredness @"Sleepiness vs. Tiredness"
#define kEventNavLearnSleep101PTSDAndSleep @"PTSD and Sleep"
#define kEventNavLearnSleep101Nightmares @"Nightmares"
#define kEventNavLearnSleep101WeaponsAndSleep @"Weapons and Sleep"
#define kEventNavLearnSleep101DepressionAndSleep @"Depression and Sleep"
#define kEventNavLearnSleep101SleepApnea @"Sleep Apnea"
#define kEventNavLearnSleep101Medications @"Medications"

#define kEventNavLearnHabitsAndSleep @"Habits and Sleep"
#define kEventNavLearnHabitsAndSleepWorryingInBed @"Worrying in Bed"
#define kEventNavLearnHabitsAndSleepWatchingTheClock @"Watching the Clock"
#define kEventNavLearnHabitsAndSleepNapping @"Napping"
#define kEventNavLearnHabitsAndSleepWindingDown @"Winding Down"
#define kEventNavLearnHabitsAndSleepUsingTheBedroom @"Using the Bedroom for Two Activities Only"
#define kEventNavLearnHabitsAndSleepEating @"Eating"
#define kEventNavLearnHabitsAndSleepCaffeineUse @"Caffeine Use"
#define kEventNavLearnHabitsAndSleepExercise @"Exercise"
#define kEventNavLearnHabitsAndSleepAlcoholUse @"Alcohol Use"
#define kEventNavLearnHabitsAndSleepNicotineUse @"Nicotine Use"
#define kEventNavLearnHabitsAndSleepGettingComfortable @"Getting Comfortable"

#define kEventNavLearnCBTiGlossary @"CBT-I Glossary"

// Tools
#define kEventTools @"Tools"
#define kEventToolsCreateNewSleepHabits @"Create New Sleep Habits"
#define kEventToolsCreateNewSleepHabitsGoToBedOnlyWhenSleepy @"Go to Bed Only When Sleepy"
#define kEventToolsCreateNewSleepHabitsGetOutOfBed @"Get Out of Bed When You Can't Sleep"
#define kEventToolsCreateNewSleepHabitsGetOutOfBedAtPrescribedTime @"Get Up at Prescribed Wake Time"
#define kEventToolsCreateNewSleepHabitsSetupSleepEnvironment @"Set Up Sleep Environment"

#define kEventToolsCreateNewSleepHabitsReducingCaffeine @"Caffeine"
#define kCaffeineDailyCaffeine @"Reducing Caffeine"
#define kCaffeineReminderSet @"Caffeine Reminder"

#define kEventToolsQuietYourMind @"Quiet Your Mind"

#define kEventToolsQuietYourMindWindingDown @"Quiet Your Mind Winding Down" //Can't be winding down since its used above already

#define kEventToolsQuietYourMindScheduleWorryTime @"Schedule Worry Time"
#define kWorryTimeTopicToThinkAbout @"Worry Time"
#define kWorryTimeReminderSet @"Worry Reminder"

#define kEventToolsQuietYourMindChangeYourPerspective @"Change Perspective"
#define kChangeYourPerspectiveTryAnotherWorriedAboutSleep @"Worried About Sleep"
#define kChangeYourPerspectiveTryAnotherThinkingAboutTrauma @"Thinking About Trauma"

#define kEventToolsQuietYourMindBreathingTool @"Breathing Tool"
#define kBreathingToolPressedPlay @"Breathe"

#define kEventToolsQuietYourMindProgressiveMuscleRelaxation @"Progressive Muscle Relaxation"
#define kMuscleRelaxationPressedPlay @"PMR"

#define kEventToolsQuietYourMindGuidedImageryForest @"Guided Imagery: Forest"
#define kGuidedImageryForestPressedPlay @"Forest"

#define kEventToolsQuietYourMindGuidedImageryCountryRoad @"Guided Imagery: Country Road"
#define kGuidedImageryCountryRoadPressedPlay @"Country Road"

#define kEventToolsQuietYourMindGuidedImageryBeach @"Guided Imagery: Beach"
#define kGuidedImageryBeachPressedPlay @"Beach"

#define kEventToolsQuietYourMindObserveThoughtsCloudsInTheSky @"Clouds"

#define kEventToolsQuietYourMindObserveSensationsBodyScan @"Body Scan"

#define kEventToolsPreventInsomniaInTheFuture @"Prevent Insomnia in the Future"

// My Sleep
#define kEventMySleep @"My Sleep"
#define kEventGraphSleepSummary @"Sleep Summary"
#define kEventGraphSleepEfficiency @"Sleep Efficiency"
#define kEventGraphFallingAsleep @"Falling Asleep"
#define kEventGraphMinutesAwake @"Minutes Awake"
#define kEventGraphWakingUp @"Waking Up"
#define kEventGraphMinutesAwakeTooEarly @"Minutes Awake Too Early"

typedef NS_ENUM(NSInteger, Graph) {
    GraphSleepSummary = 0,
    GraphSleepEfficiency = 1,
    GraphFallingAsleep = 2,
    GraphMinutesAwake = 3,
    GraphWakingUp = 4,
    GraphMinutesAwakeTooEarly = 5
};

// My Sleep -> Sleep Diary
#define kEventMySleepSleepDiary @"Sleep Diary"
#define kEventMySleepSleepDiaryAddNewEntry @"Diary Entry"
#define kSleepDiaryAddNewEntryNap @"Nap"
#define kSleepDiaryAddNewEntryNapLength @"Nap Length"
#define kSleepDiaryAddNewEntryTimeIntoBed @"Get Into Bed Time"
#define kSleepDiaryAddNewEntryTimeTryingToSleep @"Try to Sleep Time"
#define kSleepDiaryAddNewEntryTimeTilFellAsleep @"Fall Asleep Time"
#define kSleepDiaryAddNewEntryTimesWakingUp @"Wake Up Times"
#define kSleepDiaryAddNewEntryTimesWakingUpLength @"Wake Up Times Length"
#define kSleepDiaryAddNewEntryTimeFinallyAwakening @"Final Awakening"
#define kSleepDiaryAddNewEntryWokeUpEarlierThanDesired @"Wake Too Early"
#define kSleepDiaryAddNewEntryWokeUpEarlierThanDesiredHowEarly @"How Early"
#define kSleepDiaryAddNewEntryTimeOutOfBed @"Out of Bed Time"
#define kSleepDiaryAddNewEntrySleepQualityRating @"Sleep Quality"
#define kSleepDiaryAddNewEntryComments @"Comments"
#define kSleepDiaryAddNewEntryDateEdited @"Diary Edited Date"
#define kSleepDiaryAddNewEntryEntryDate @"Diary Entry Date"
#define kSleepDiaryAddNewEntrySaved @"Diary Saved"
#define kSleepDiaryAddNewEntryReminderSet @"Diary Reminder"

// My Sleep -> Assessments
#define kEventMySleepAssessments @"Assessments"
#define kEventMySleepAssessmentsPreviousAssessments @"Previous Assessments"
#define kEventMySleepAssessmentsAssessmentStarted @"Assessment Started"
#define kEventMySleepAssessmentsNewAssessment @"New Assessment"
#define kEventMySleepAssessmentsAssessmentCompleted @"Assessment Completed"
#define kAssessmentsNewAssessmentScheduledNextAssessment @"Scheduled Next Assessment"

#define kAssessmentsPremature @"Premature Assessment"
#define kAssessmentsShowAssessmentDetails @"Show Assessment Details"
#define kAssessmentsClearHistory @"Clear History"

// Sleep Prescription
#define kEventSleepPrescriptionUpdatePrescription @"Update Sleep Rx"
#define kUpdatePrescriptionDate @"Update Sleep Rx Date"
#define kUpdatePrescriptionContinueUpdating @"Continue Updating Sleep Rx"
#define kUpdatePrescriptionSleepUpdateWarning @"Sleep Rx Update Warning"
#define kUpdatePrescriptionSleepUpdateWarningOverride @"Sleep Rx Update Warning Override?"
#define kUpdatePrescriptionDesiredWakeUpTime @"Desired Wake Up Time"
#define kUpdatePrescriptionSNQAdjustment @"SNQ Adjustment"
#define kUpdatePrescriptionPrescribedBedTime @"Prescribed Bedtime"
#define kUpdatePrescriptionPrescribedWakeUpTime @"Prescribed Wake Up Time"
#define kUpdatePrescriptionAdjustedPrescribedBedTime @"Adjusted Prescribed Bedtime"
#define kUpdatePrescriptionAdjustedWakeUpTime @"Adjusted Wake Up Time"
#define kUpdatePrescriptionAcceptPrescribedSleepRx @"Accept Prescribed Sleep Rx"
