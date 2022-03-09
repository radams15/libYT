
unit ytall;
interface

{
  Automatically converted by H2Pas 1.0.0 from /Volumes/share/scripts/VTube/ytall.tmp.h
  The following command line parameters were used:
    -e
    -p
    -D
    -w
    -o
    /Volumes/share/scripts/VTube/ytall.pas
    /Volumes/share/scripts/VTube/ytall.tmp.h
}

  const
    External_library='libyt'; {Setup as you need}

  { Pointers to basic pascal types, inserted by h2pas conversion program.}
  






  Type
  Channel = record
        id : Pchar;
        name : Pchar;
      end;
  PChannel  = ^Channel;
  Channel_t = Channel;
  PChannel_t  = ^Channel_t;

  Subs = record
        arry : ^PChannel_t;
        length : longint;
      end;
  PSubs  = ^Subs;
  Config = record
        fname : Pchar;
        quality : longint;
        subs : PSubs;
        invidious_inst : Pchar;
        use_threading : longint;
        use_proxy : longint;
        proxy_url : Pchar;
      end;
  PConfig  = ^Config;
  Config_t = Config;
  PConfig_t  = ^Config_t;
  Subs_t = Subs;
  PSubs_t  = ^Subs_t;
  Video = record
        id : Pchar;
        title : Pchar;
        channel_name : Pchar;
        channel_id : Pchar;
        published : longint;
      end;
  PVideo  = ^Video;
  Video_t = Video;
  PVideo_t  = ^Video_t;
  Videos = record
        arry : ^PVideo;
        length : longint;
      end;
  PVideos  = ^Videos;
  Videos_t = Videos;
  PVideos_t  = ^Videos_t;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}



  type

    stream_cb = procedure (_para1:pointer; _para2:longint);cdecl;
(* Const before type ignored *)
(* Const before type ignored *)
(* Const before type ignored *)

  function net_get(url:Pchar; use_proxy:longint; proxy:Pchar):Pchar;cdecl;external External_library name 'net_get';

(* Const before type ignored *)
(* Const before type ignored *)
  function net_stream(url:Pchar; stream_func:stream_cb; use_proxy:longint; proxy:Pchar):longint;cdecl;external External_library name 'net_stream';


  function video_new:PVideo_t;cdecl;external External_library name 'video_new';

  procedure video_free(var video:Video_t);cdecl;external External_library name 'video_free';


  procedure videos_free(var vids:Videos_t);cdecl;external External_library name 'videos_free';

  function videos_get(var vids:Videos_t; index:longint):PVideo_t;cdecl;external External_library name 'videos_get';


  type

    vid_cb = procedure (_para1:PVideo_t; _para2:pointer);cdecl;
(* Const before type ignored *)
(* Const before type ignored *)
(* Const before type ignored *)


(* Const before type ignored *)

  function channel_new(id:Pchar):PChannel_t;cdecl;external External_library name 'channel_new';

(* Const before type ignored *)
  function channel_new_from_name(name:Pchar; var conf:Config_t):PChannel_t;cdecl;external External_library name 'channel_new_from_name';

(* Const before type ignored *)
  function channel_name(var channel:Channel_t; var conf:Config_t):Pchar;cdecl;external External_library name 'channel_name';

  function channel_get_vids(var channel:Channel_t; var conf:Config_t; callback:vid_cb; data:pointer):longint;cdecl;external External_library name 'channel_get_vids';

  procedure channel_free(var channel:Channel_t);cdecl;external External_library name 'channel_free';


(* Const before type ignored *)

  function config_new(fname:Pchar; use_proxy:longint):PConfig_t;cdecl;external External_library name 'config_new';

  procedure config_subs_add(var conf:Config_t; var channel:Channel_t);cdecl;external External_library name 'config_subs_add';

  procedure config_save(var conf:Config_t);cdecl;external External_library name 'config_save';

  function config_get_vids_list(var conf:Config_t):PVideos_t;cdecl;external External_library name 'config_get_vids_list';

  function config_get_vids(var conf:Config_t; callback:vid_cb; data:pointer):longint;cdecl;external External_library name 'config_get_vids';

(* Const before type ignored *)
  function video_get_playable(var video:Video_t; var conf:Config_t):Pchar;cdecl;external External_library name 'video_get_playable';

  procedure config_free(var conf:Config_t);cdecl;external External_library name 'config_free';


implementation


end.
