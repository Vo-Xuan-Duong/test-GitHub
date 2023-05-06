import pytube
import os

class vid:
    def __init__(self, url):
        self.url  = url
        
    def is_valid_url(self):
        try:
            #sử dụng phương thức validate_url để kiểm tra tính hợp lệ của URL
            pytube.YouTube(self.url)
            return True
        except pytube.exceptions.RegexmatchError:
            return False
        
    def dowload_video(self, video):
        #liệt kê các định dạng và chất lượng video có thể tải về
        while True:
            format_dict ={} 
            os.system("cls")
            total = 0 
            for i, stream in enumerate(video.streams.filter().order_by('resolution')):
                format_dict[i] = stream
                print(f"{i}: {stream.resolation} ({stream.mine_type})")
                total = i
                
            #Nhập số thứ tự của đinh dạng và chất lượng muốn tải về
            try:
                format_index = int(input("chọn số thứ tự của chất lượng bạn muốn tải về:"))
            except:
                continue
            
            if format_index <0 or format_index > total:
                continue
            stream = format_dict[format_index]
            break
        
        #tải về video
        stream.dowload()
        print("Tải về thành công!")
    
    def dowload_audio(sefl, video):
        #Liệt kê các định dạng và chất lượng âm thanh có thể tải về
        while True:
            format_dict = {}
            os.system("cls")
            for i, stream in enumerate(video.streams.filter(type= "audio")):
                format_dict[i] = stream
                print(f"{i}: {stream.abr} ({stream.mime_type})")
                total  = i
                
            #Nhập số thứ tự của định dạng và chất lượng muons tải về
            try:
                format_index = int(input("chọn số thứ tự của chất lượng muốn tải về: "))
            except:
                continue
            
            if format_index < 0 or format_index > total:
                continue
            stream = format_dict[format_index]
            break
        
        #Tải về audio
        stream.dowload()
        print("Tải audio thành công! ")