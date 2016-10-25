//
//  AnalyticsConstants.h
//  MindfulnessCoach
//
//  Created by Thomas Malcolm on 6/10/15.
//
//

#define kAnalyticsTimestampFormat @"%ld-%02ld-%02ld'T'%02ld:%02ld:%02ld"
#define kContentHTMLURLInviteCodeScreen @"inviteCode.html"
#define kEventInviteCodeConfirmed @"Invite Code Confirmed"

/****************** Navigation Events *******************/

#define kEventTabBarItemSelected @"TAB_BAR_ITEM_SELECTED"

// ? -> Home
#define kEventNavHome @"Home"

// ? -> Help
#define kEventNavHelp @"Help"

// ? + Back
#define kEventNavBack @"Back"

// ? + Done
#define kEventNavDone @"Done"

// ? + Cancel
#define kEventNavCancel @"Cancel"

// ? + Modal Dismiss
#define kEventNavModalDismiss @"Modal Dismiss Button Tapped"

//Home -> A Menu Selection
#define kEventNavHomeToAMenuOption @"HOME_MENU_OPTION_SELECTED"
#define kEventNavHomeToAbout @"About"
#define kEventNavHomeToLearn @"Learn"
#define kEventNavHomeToPracticeMindfulness @"Practice Mindfulness"
#define kEventNavHomeToTrackProgress @"Track Your Progress"
#define kEventNavHomeToReminders @"Reminders"

// View Progress
#define kEventViewLastMonthsProgress @"View Last Month's Progress"
#define kEventViewLastTwoWeeksProgress @"View Progress of Last Two Weeks"
#define kEventViewLastWeeksProgress @"View Progress of Last Week"

//Activity Logs
#define kEventNavActivitiesViewControllerCreateLogEntry @"Create Log Entry Form"
#define kEventNavOpenActivityLog @"Viewing Activity Log"
#define kEventNavSaveLogEntry @"Save Log Entry"
#define kEventNavCancelPhotoSelection @"Cancel Photo Selection"
#define kEventDeleteButtonTapped @"Delete Log Button Tapped"
#define kEventConfirmDeleteLog @"Confirmation of Delete Action"
#define kEventCancelDeleteLogAction @"Cancelled Log Delete"
#define kEventEmailLogEntryButton @"Tapped E-mail Log Button"
#define kEventCancelEmailLog @"Cancelled Emailing Log Button"
#define kEventContinueEmailLog @"Continue with Emailing of Log"

//About
#define kEventNavAboutMindfulnessCoach @"About Mindfulness Coach"
#define kEventNavAboutProjectTeam @"About Project Team"
#define kEventNavAboutProjectPartners @"About Project Partners"
#define kEventNavAboutSettings @"About Settings"

//Learn
#define kEventNavLearnWhatIsMindfulness @"What is Mindfullness?"
#define kEventNavLearnWhyPracticeMindfulness @"Why Practice Mindfulness?"
#define kEventNavLearnMindfulnessForVetrans @"Mindfulness For Vetrans"
#define kEventNavLearnBenefitsOfMindfulnessForPTSD @"Benefits of Mindfulness"
#define kEventNavLearnPracticeChallengesWithPTSD @"Practice Challenges"
#define kEventNavLearnPTSDSymptomsDuringPractice @"PTSD Symtoms During Practice"

//Practice Activities
#define kEventNavPracticeAwarenessOfBreath @"Awareness of Breath"
#define kEventNavPracticeMindfulBreathing @"Mindful Breathing"
#define kEventNavPracticeMindfulWalking @"Mindful Walking"
#define kEventNavPracticeMindfulEating @"Mindful Eating"
#define kEventNavPracticeMindfulListening @"Mindful Listening"
#define kEventNavPracticeMindfulLooking @"Mindful Looking"
#define kEventNavPracticeLeavesOnAStream @"Leaves on a Stream"
#define kEventNavPracticeCloudsInTheSky @"Clounds in the Sky"
#define kEventNavPracticeBodyScan @"Body Scan"
#define kEventNavPracticeEmotionalDiscomfort @"EmotionalDiscomfort"

#define kEventNavSelectActivity @"Select Activity to Schedule"
#define kEventNavAddActivity @"Go To showEventControllerWithEventStore"
#define kEventNavAddActivityToLog @"Log Current Activity"

//Track Progress
#define kEventNavTrackToMindfulnessLog @"Track -> Mindfullness Log"
#define kEventNavTrackToTrackYourProgress @"Track -> Track Your Progress"

//Reminders
#define kEventNavRemindersToScheduleActivity @"Reminders -> Schedule Activity"
#define kEventNavRemindersToSetRandomReminders @"Reminders -> Set Random Reminders"
#define kEventNavRemindersToRemindMeToLog @"Reminders -> Remind Me To Log"
#define kEventNavCancelRemindersUpdate @"Cancel Reminders Update"

//Blackouts Controller
#define kEventNavCreateBlackout @"Create Blackout"
#define kEventNavCancelBlackout @"Cancel Making Blackout"
#define kEventNavToBlackoutsList @"Nav To Blackouts List"

//Activity Options Buttons
#define kEventNavMyEnvironmentListening @"Listen to My Environment"
#define kEventNavMySongsListening @"Listen to My Songs"
#define kEventNavMyPhotoWatching @"Watch My Photos"



/****************** Non Navigation Based ******************/

// Practice Activity Buttons
#define kEventStartSongListening @"Started Listening to Songs"
#define kEventStartPhotoWatching @"Started Watching Photos"
#define kEventStartEnvironmentListening @"Started Listening to Environment"
#define kEventMissingSong @"Song Missing"
#define kEventRestartActivity @"Activity Restarted"
#define kEventStopActivity @"Activity Stopped"
#define kEventActivityPaused @"Activity Paused"
#define kEventActivityUnpaused @"Activity Unpaused"
#define kEventSkipButtonPressed @"Skip Button"

// Notification Frequency
#define kEventFrequencySet_None @"Frequency - None"
#define kEventFrequencySet_Daily @"Frequency - Daily"
#define kEventFrequencySet_Weekly @"Frequency - Weekly"
#define kEventFrequencySet_Monthly @"Frequency - Monthly"

// Activity Log Tools
#define kEventDeleteLogEntry @"Log Deleted"
#define kLogInfoExercise @"Exercise Type"
#define kLogInfoDate @"Log Date"
#define kLogInfoDuration @"Duration of Practice"
#define kLogInfoAudioGuided @"AudioGuided"
#define kLogInfoComments @"Log Comments"
#define kLogInfoTimeOfDeletion @"Time of Deletion"

//Remind Me To Log
#define kReminderFrequency @"Reminder Frequency"
#define kReminderTimeOfDay @"Remind during Time of Day"
#define kReminderAudioAlert @"Audio Alert Status"
#define kReminderTimeSaved @"Time Reminder Updated/Saved"
#define kEventSaveRemindMeToLog @"Reminder Saved"
#define kEventSaveBlackOutSpan @"Black Out Span Saved"
#define kEventDeleteBlackOutSpan @"Black Out Span Deleted"

//Settings
#define kEventUserWantsToBeTracked @"User Tracked"
#define kEventUserDoesntWantToBeTracked @"User Not Tracked"
#define kEventPurgeUserDataPressed @"User Data Delete Button Pressed"
#define kEventPurgeUserDataConfirmed @"User Data Delete Confirmed"
#define kEventCancelledUserDataPurge @"User Decided Against Data Purge"

//Photo and Song Selection Related
#define kEventNavSelectPhotos @"To Select Photos"
#define kEventNavSelectSongs @"To Select Songs"
#define kEventSelectionGreaterThanMax @"Selection > Max"
#define kEventSongAdded @"Song Added"
#define kEventNumberOfSongs @"Song Selection Count"
#define kEventNumberOfPhotos @"Photo Selection Count"

//Email Related
#define kEventLogEmailSent @"Email Sent"
#define kEventLogEmailCancelled @"Email Cancelled"
#define kEventLogEmailSavedForLater @"Email Saved"
#define kEventLogEmailFailed_ERROR @"Email Failed!"

//Calendar Event Creation
#define kEventCalendarAccessDenied @"Calendar Access Denied"
#define kLogCalendarStartDate @"Start Date"
#define kLogCalendarEventTitle @"Event Title"
#define kLogCalendarEventCreationTime @"Event Created"
#define kEventCalendarEventCreated @"Successfuly Created Event"
#define kEventCalendarCreationCancelled @"Calendar Event Cancelled"

//Log Editing
#define kEventEditLogExercise @"Changing Logged Exercise"
#define kEventEditLogTime @"Changing Logged Time"
#define kEventEditLogDuration @"Changing Logged Duration"
#define kEventEditLogDate @"Changing Logged Date"
#define kEventEditLogAudioGuided @"Flipping Log Audio Status"
#define kEventEditLogComments @"Changing Logged Comments"
#define kEventCancelLogEntry @"Cancel Log Entry"

//Editing Reminders
#define kEventNavToFrequencyController @"Nav To Frequency Selection"
#define kEventAudioSettingSwitched @"Audio Switched"
#define kEventSelectTimeOfDay @"Select Remind Time"
