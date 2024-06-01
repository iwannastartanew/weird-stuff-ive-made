import datetime

#get current date and time
now = datetime.datetime.now()
#define day and month names
days = ["Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday","Sunday"]
months = ["January","February","March","April","May","June", "July","August","September","October","November","December"]
#get the day and month
current_day = days[now.weekday()]
current_month = months[now.month - 1]
#get the current time
current_time = "{:02d}:{:02d}:{:02d}".format(now.hour, now.minute, now.second)
#print current date and time
print("Current time in your country is {}, {} {}, {} and the time is {}".format(current_day, current_month, now.day, now.year, current_time))
#define water intake recommendations
recommendations = {
    (0, 4): ("Midnight", "Minimal intake to avoid disrupting sleep patterns."),
    (4, 6): ("Early Morning", "Moderate intake to avoid disrupting sleep patterns."),
    (6, 9): ("Morning", "Helps kickstart metabolism and aids digestion."),
    (9, 12): ("Early Noon", "Maintains hydration levels as the day progresses."),
    (12, 14): ("Noon", "Supports hydration during peak activity times."),
    (14, 17): ("Afternoon", "Prevents dehydration and fatigue."),
    (17, 19): ("Early Evening", "Keeps you hydrated as you wind down from the day."),
    (19, 22): ("Evening", "Helps maintain hydration without disrupting sleep."),
    (22, 24): ("Night", "Moderate intake to avoid disturbances during sleep.")
}
#determine current intake recommendation
for (start, end), (time, recommendation) in recommendations.items():
    if start <= now.hour < end:
        intake_time = time
        intake_recommendation = recommendation
        break
#determine cups of water recommended
if 6 <= now.hour < 9:
    cups = 1
elif 9 <= now.hour < 12 or 19 <= now.hour < 22:
    cups = 2
elif 12 <= now.hour < 14 or 17 <= now.hour < 19:
    cups = 3
else:
    cups = 1
print("You should drink {} cup(s) of water at {}. {}".format(cups, intake_time, intake_recommendation))
