/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package uk.co.therhys.LibYT;

public class yt {
  public static void Channel_t_id_set(SWIGTYPE_p_Channel self, String value) {
    ytJNI.Channel_t_id_set(SWIGTYPE_p_Channel.getCPtr(self), value);
  }

  public static String Channel_t_id_get(SWIGTYPE_p_Channel self) {
    return ytJNI.Channel_t_id_get(SWIGTYPE_p_Channel.getCPtr(self));
  }

  public static void Channel_t_name_set(SWIGTYPE_p_Channel self, String value) {
    ytJNI.Channel_t_name_set(SWIGTYPE_p_Channel.getCPtr(self), value);
  }

  public static String Channel_t_name_get(SWIGTYPE_p_Channel self) {
    return ytJNI.Channel_t_name_get(SWIGTYPE_p_Channel.getCPtr(self));
  }

  public static void Channel_t_sub_count_set(SWIGTYPE_p_Channel self, int value) {
    ytJNI.Channel_t_sub_count_set(SWIGTYPE_p_Channel.getCPtr(self), value);
  }

  public static int Channel_t_sub_count_get(SWIGTYPE_p_Channel self) {
    return ytJNI.Channel_t_sub_count_get(SWIGTYPE_p_Channel.getCPtr(self));
  }

  public static void Channel_t_video_count_set(SWIGTYPE_p_Channel self, int value) {
    ytJNI.Channel_t_video_count_set(SWIGTYPE_p_Channel.getCPtr(self), value);
  }

  public static int Channel_t_video_count_get(SWIGTYPE_p_Channel self) {
    return ytJNI.Channel_t_video_count_get(SWIGTYPE_p_Channel.getCPtr(self));
  }

  public static SWIGTYPE_p_Channel new_Channel_t() {
    long cPtr = ytJNI.new_Channel_t();
    return (cPtr == 0) ? null : new SWIGTYPE_p_Channel(cPtr, true);
  }

  public static void delete_Channel_t(SWIGTYPE_p_Channel self) {
    ytJNI.delete_Channel_t(SWIGTYPE_p_Channel.getCPtr(self));
  }

  public static void Channels_t_arry_set(SWIGTYPE_p_Channels self, SWIGTYPE_p_p_Channel value) {
    ytJNI.Channels_t_arry_set(SWIGTYPE_p_Channels.getCPtr(self), SWIGTYPE_p_p_Channel.getCPtr(value));
  }

  public static SWIGTYPE_p_p_Channel Channels_t_arry_get(SWIGTYPE_p_Channels self) {
    long cPtr = ytJNI.Channels_t_arry_get(SWIGTYPE_p_Channels.getCPtr(self));
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_Channel(cPtr, false);
  }

  public static void Channels_t_length_set(SWIGTYPE_p_Channels self, int value) {
    ytJNI.Channels_t_length_set(SWIGTYPE_p_Channels.getCPtr(self), value);
  }

  public static int Channels_t_length_get(SWIGTYPE_p_Channels self) {
    return ytJNI.Channels_t_length_get(SWIGTYPE_p_Channels.getCPtr(self));
  }

  public static SWIGTYPE_p_Channels new_Channels_t() {
    long cPtr = ytJNI.new_Channels_t();
    return (cPtr == 0) ? null : new SWIGTYPE_p_Channels(cPtr, true);
  }

  public static void delete_Channels_t(SWIGTYPE_p_Channels self) {
    ytJNI.delete_Channels_t(SWIGTYPE_p_Channels.getCPtr(self));
  }

  public static SWIGTYPE_p_Channel channel_new(String id) {
    long cPtr = ytJNI.channel_new(id);
    return (cPtr == 0) ? null : new SWIGTYPE_p_Channel(cPtr, false);
  }

  public static String vid_get_thumbnail(SWIGTYPE_p_void thumbnails) {
    return ytJNI.vid_get_thumbnail(SWIGTYPE_p_void.getCPtr(thumbnails));
  }

  public static SWIGTYPE_p_Channel channel_new_from_name(String name, SWIGTYPE_p_Config conf) {
    long cPtr = ytJNI.channel_new_from_name(name, SWIGTYPE_p_Config.getCPtr(conf));
    return (cPtr == 0) ? null : new SWIGTYPE_p_Channel(cPtr, false);
  }

  public static void channel_search(SWIGTYPE_p_Config conf, String query, int page, SWIGTYPE_p_f_p_struct_Channel_p_void__void callback, SWIGTYPE_p_void data) {
    ytJNI.channel_search(SWIGTYPE_p_Config.getCPtr(conf), query, page, SWIGTYPE_p_f_p_struct_Channel_p_void__void.getCPtr(callback), SWIGTYPE_p_void.getCPtr(data));
  }

  public static SWIGTYPE_p_List channel_search_list(SWIGTYPE_p_Config conf, String query, int page) {
    long cPtr = ytJNI.channel_search_list(SWIGTYPE_p_Config.getCPtr(conf), query, page);
    return (cPtr == 0) ? null : new SWIGTYPE_p_List(cPtr, false);
  }

  public static String channel_name(SWIGTYPE_p_Channel channel, SWIGTYPE_p_Config conf) {
    return ytJNI.channel_name(SWIGTYPE_p_Channel.getCPtr(channel), SWIGTYPE_p_Config.getCPtr(conf));
  }

  public static int channel_get_vids(SWIGTYPE_p_Channel channel, SWIGTYPE_p_Config conf, SWIGTYPE_p_f_p_struct_Video_p_void__void callback, SWIGTYPE_p_void data) {
    return ytJNI.channel_get_vids(SWIGTYPE_p_Channel.getCPtr(channel), SWIGTYPE_p_Config.getCPtr(conf), SWIGTYPE_p_f_p_struct_Video_p_void__void.getCPtr(callback), SWIGTYPE_p_void.getCPtr(data));
  }

  public static SWIGTYPE_p_List channel_get_vids_list(SWIGTYPE_p_Channel channel, SWIGTYPE_p_Config conf) {
    long cPtr = ytJNI.channel_get_vids_list(SWIGTYPE_p_Channel.getCPtr(channel), SWIGTYPE_p_Config.getCPtr(conf));
    return (cPtr == 0) ? null : new SWIGTYPE_p_List(cPtr, false);
  }

  public static void channel_free(SWIGTYPE_p_Channel channel) {
    ytJNI.channel_free(SWIGTYPE_p_Channel.getCPtr(channel));
  }

  public static void Config_t_fname_set(SWIGTYPE_p_Config self, String value) {
    ytJNI.Config_t_fname_set(SWIGTYPE_p_Config.getCPtr(self), value);
  }

  public static String Config_t_fname_get(SWIGTYPE_p_Config self) {
    return ytJNI.Config_t_fname_get(SWIGTYPE_p_Config.getCPtr(self));
  }

  public static void Config_t_quality_set(SWIGTYPE_p_Config self, int value) {
    ytJNI.Config_t_quality_set(SWIGTYPE_p_Config.getCPtr(self), value);
  }

  public static int Config_t_quality_get(SWIGTYPE_p_Config self) {
    return ytJNI.Config_t_quality_get(SWIGTYPE_p_Config.getCPtr(self));
  }

  public static void Config_t_subs_set(SWIGTYPE_p_Config self, SWIGTYPE_p_List value) {
    ytJNI.Config_t_subs_set(SWIGTYPE_p_Config.getCPtr(self), SWIGTYPE_p_List.getCPtr(value));
  }

  public static SWIGTYPE_p_List Config_t_subs_get(SWIGTYPE_p_Config self) {
    long cPtr = ytJNI.Config_t_subs_get(SWIGTYPE_p_Config.getCPtr(self));
    return (cPtr == 0) ? null : new SWIGTYPE_p_List(cPtr, false);
  }

  public static void Config_t_invidious_inst_set(SWIGTYPE_p_Config self, String value) {
    ytJNI.Config_t_invidious_inst_set(SWIGTYPE_p_Config.getCPtr(self), value);
  }

  public static String Config_t_invidious_inst_get(SWIGTYPE_p_Config self) {
    return ytJNI.Config_t_invidious_inst_get(SWIGTYPE_p_Config.getCPtr(self));
  }

  public static void Config_t_use_threading_set(SWIGTYPE_p_Config self, int value) {
    ytJNI.Config_t_use_threading_set(SWIGTYPE_p_Config.getCPtr(self), value);
  }

  public static int Config_t_use_threading_get(SWIGTYPE_p_Config self) {
    return ytJNI.Config_t_use_threading_get(SWIGTYPE_p_Config.getCPtr(self));
  }

  public static void Config_t_use_proxy_set(SWIGTYPE_p_Config self, int value) {
    ytJNI.Config_t_use_proxy_set(SWIGTYPE_p_Config.getCPtr(self), value);
  }

  public static int Config_t_use_proxy_get(SWIGTYPE_p_Config self) {
    return ytJNI.Config_t_use_proxy_get(SWIGTYPE_p_Config.getCPtr(self));
  }

  public static void Config_t_proxy_url_set(SWIGTYPE_p_Config self, String value) {
    ytJNI.Config_t_proxy_url_set(SWIGTYPE_p_Config.getCPtr(self), value);
  }

  public static String Config_t_proxy_url_get(SWIGTYPE_p_Config self) {
    return ytJNI.Config_t_proxy_url_get(SWIGTYPE_p_Config.getCPtr(self));
  }

  public static SWIGTYPE_p_Config new_Config_t() {
    long cPtr = ytJNI.new_Config_t();
    return (cPtr == 0) ? null : new SWIGTYPE_p_Config(cPtr, true);
  }

  public static void delete_Config_t(SWIGTYPE_p_Config self) {
    ytJNI.delete_Config_t(SWIGTYPE_p_Config.getCPtr(self));
  }

  public static SWIGTYPE_p_Config config_new(String fname, int use_proxy) {
    long cPtr = ytJNI.config_new(fname, use_proxy);
    return (cPtr == 0) ? null : new SWIGTYPE_p_Config(cPtr, false);
  }

  public static void config_subs_add(SWIGTYPE_p_Config conf, SWIGTYPE_p_Channel channel) {
    ytJNI.config_subs_add(SWIGTYPE_p_Config.getCPtr(conf), SWIGTYPE_p_Channel.getCPtr(channel));
  }

  public static void config_subs_rm(SWIGTYPE_p_Config conf, SWIGTYPE_p_Channel channel) {
    ytJNI.config_subs_rm(SWIGTYPE_p_Config.getCPtr(conf), SWIGTYPE_p_Channel.getCPtr(channel));
  }

  public static void config_save(SWIGTYPE_p_Config conf) {
    ytJNI.config_save(SWIGTYPE_p_Config.getCPtr(conf));
  }

  public static SWIGTYPE_p_List config_get_vids_list(SWIGTYPE_p_Config conf) {
    long cPtr = ytJNI.config_get_vids_list(SWIGTYPE_p_Config.getCPtr(conf));
    return (cPtr == 0) ? null : new SWIGTYPE_p_List(cPtr, false);
  }

  public static int config_get_vids(SWIGTYPE_p_Config conf, SWIGTYPE_p_f_p_struct_Video_p_void__void callback, SWIGTYPE_p_void data) {
    return ytJNI.config_get_vids(SWIGTYPE_p_Config.getCPtr(conf), SWIGTYPE_p_f_p_struct_Video_p_void__void.getCPtr(callback), SWIGTYPE_p_void.getCPtr(data));
  }

  public static String video_get_playable(SWIGTYPE_p_Video video, SWIGTYPE_p_Config conf) {
    return ytJNI.video_get_playable(SWIGTYPE_p_Video.getCPtr(video), SWIGTYPE_p_Config.getCPtr(conf));
  }

  public static void config_free(SWIGTYPE_p_Config conf) {
    ytJNI.config_free(SWIGTYPE_p_Config.getCPtr(conf));
  }

  public static void config_video_search(SWIGTYPE_p_Config conf, String query, int page, SWIGTYPE_p_f_p_struct_Video_p_void__void callback, SWIGTYPE_p_void data) {
    ytJNI.config_video_search(SWIGTYPE_p_Config.getCPtr(conf), query, page, SWIGTYPE_p_f_p_struct_Video_p_void__void.getCPtr(callback), SWIGTYPE_p_void.getCPtr(data));
  }

  public static SWIGTYPE_p_List config_video_search_list(SWIGTYPE_p_Config conf, String query, int page) {
    long cPtr = ytJNI.config_video_search_list(SWIGTYPE_p_Config.getCPtr(conf), query, page);
    return (cPtr == 0) ? null : new SWIGTYPE_p_List(cPtr, false);
  }

  public static void Video_t_id_set(SWIGTYPE_p_Video self, String value) {
    ytJNI.Video_t_id_set(SWIGTYPE_p_Video.getCPtr(self), value);
  }

  public static String Video_t_id_get(SWIGTYPE_p_Video self) {
    return ytJNI.Video_t_id_get(SWIGTYPE_p_Video.getCPtr(self));
  }

  public static void Video_t_title_set(SWIGTYPE_p_Video self, String value) {
    ytJNI.Video_t_title_set(SWIGTYPE_p_Video.getCPtr(self), value);
  }

  public static String Video_t_title_get(SWIGTYPE_p_Video self) {
    return ytJNI.Video_t_title_get(SWIGTYPE_p_Video.getCPtr(self));
  }

  public static void Video_t_channel_name_set(SWIGTYPE_p_Video self, String value) {
    ytJNI.Video_t_channel_name_set(SWIGTYPE_p_Video.getCPtr(self), value);
  }

  public static String Video_t_channel_name_get(SWIGTYPE_p_Video self) {
    return ytJNI.Video_t_channel_name_get(SWIGTYPE_p_Video.getCPtr(self));
  }

  public static void Video_t_channel_id_set(SWIGTYPE_p_Video self, String value) {
    ytJNI.Video_t_channel_id_set(SWIGTYPE_p_Video.getCPtr(self), value);
  }

  public static String Video_t_channel_id_get(SWIGTYPE_p_Video self) {
    return ytJNI.Video_t_channel_id_get(SWIGTYPE_p_Video.getCPtr(self));
  }

  public static void Video_t_thumbnail_set(SWIGTYPE_p_Video self, String value) {
    ytJNI.Video_t_thumbnail_set(SWIGTYPE_p_Video.getCPtr(self), value);
  }

  public static String Video_t_thumbnail_get(SWIGTYPE_p_Video self) {
    return ytJNI.Video_t_thumbnail_get(SWIGTYPE_p_Video.getCPtr(self));
  }

  public static void Video_t_published_set(SWIGTYPE_p_Video self, int value) {
    ytJNI.Video_t_published_set(SWIGTYPE_p_Video.getCPtr(self), value);
  }

  public static int Video_t_published_get(SWIGTYPE_p_Video self) {
    return ytJNI.Video_t_published_get(SWIGTYPE_p_Video.getCPtr(self));
  }

  public static SWIGTYPE_p_Video new_Video_t() {
    long cPtr = ytJNI.new_Video_t();
    return (cPtr == 0) ? null : new SWIGTYPE_p_Video(cPtr, true);
  }

  public static void delete_Video_t(SWIGTYPE_p_Video self) {
    ytJNI.delete_Video_t(SWIGTYPE_p_Video.getCPtr(self));
  }

  public static SWIGTYPE_p_Video video_new() {
    long cPtr = ytJNI.video_new();
    return (cPtr == 0) ? null : new SWIGTYPE_p_Video(cPtr, false);
  }

  public static void video_free(SWIGTYPE_p_Video video) {
    ytJNI.video_free(SWIGTYPE_p_Video.getCPtr(video));
  }

  public static void List_t_arry_set(SWIGTYPE_p_List self, SWIGTYPE_p_p_void value) {
    ytJNI.List_t_arry_set(SWIGTYPE_p_List.getCPtr(self), SWIGTYPE_p_p_void.getCPtr(value));
  }

  public static SWIGTYPE_p_p_void List_t_arry_get(SWIGTYPE_p_List self) {
    long cPtr = ytJNI.List_t_arry_get(SWIGTYPE_p_List.getCPtr(self));
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_void(cPtr, false);
  }

  public static void List_t_length_set(SWIGTYPE_p_List self, int value) {
    ytJNI.List_t_length_set(SWIGTYPE_p_List.getCPtr(self), value);
  }

  public static int List_t_length_get(SWIGTYPE_p_List self) {
    return ytJNI.List_t_length_get(SWIGTYPE_p_List.getCPtr(self));
  }

  public static SWIGTYPE_p_List new_List_t() {
    long cPtr = ytJNI.new_List_t();
    return (cPtr == 0) ? null : new SWIGTYPE_p_List(cPtr, true);
  }

  public static void delete_List_t(SWIGTYPE_p_List self) {
    ytJNI.delete_List_t(SWIGTYPE_p_List.getCPtr(self));
  }

  public static void videos_free(SWIGTYPE_p_List vids) {
    ytJNI.videos_free(SWIGTYPE_p_List.getCPtr(vids));
  }

  public static void channels_free(SWIGTYPE_p_List channels) {
    ytJNI.channels_free(SWIGTYPE_p_List.getCPtr(channels));
  }

  public static int list_length(SWIGTYPE_p_List vids) {
    return ytJNI.list_length(SWIGTYPE_p_List.getCPtr(vids));
  }

  public static SWIGTYPE_p_Video videos_get(SWIGTYPE_p_List vids, int index) {
    long cPtr = ytJNI.videos_get(SWIGTYPE_p_List.getCPtr(vids), index);
    return (cPtr == 0) ? null : new SWIGTYPE_p_Video(cPtr, false);
  }

  public static SWIGTYPE_p_Channel channels_get(SWIGTYPE_p_List vids, int index) {
    long cPtr = ytJNI.channels_get(SWIGTYPE_p_List.getCPtr(vids), index);
    return (cPtr == 0) ? null : new SWIGTYPE_p_Channel(cPtr, false);
  }

}