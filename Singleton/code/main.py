def singleton(class_):
    instances = {}

    def getinstance(*args, **kwargs):
        if class_ not in instances:
            instances[class_] = class_(*args, **kwargs)
        return instances[class_]

    return getinstance


@singleton
class Settings:

    def __init__(self):
        self.__volume = 5
        self.__brightness = 5

    def set_volume(self, volume):
        self.__volume = volume
        print(f"Volume was set to {volume}")

    def set_brightness(self, brightness):
        self.__brightness = brightness
        print(f"Brightness was set to {brightness}")


settings = Settings()


class App:

    def __init__(self, login: str):
        self.__login = login

    def adjust_setting(self, setting: str, value):
        if setting == "volume":
            settings.set_volume(value)
        elif setting == "brightness":
            settings.set_brightness(value)
        else:
            print(f"Setting \"{setting}\" is not implemented yet")


app = App("Marek")
app.adjust_setting("volume", 8.15)
app.adjust_setting("brightness", 1.25)
app.adjust_setting("marchew", 16)
