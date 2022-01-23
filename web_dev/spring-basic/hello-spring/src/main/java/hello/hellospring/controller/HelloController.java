package hello.hellospring.controller;

import org.springframework.boot.Banner;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

    @GetMapping("hello")
    public String hello(Model model) {
        // key가 데이터, value가 "hello!!"인 모델 속성 설정
        model.addAttribute("data","hello!!");
        // "hello"를 리턴하면 기본적으로 스프링부트가 resources/templates/<리턴값>.html 찾아감
        return "hello";
    }

    // command + p : 파라미터 정보
    @GetMapping("hello-mvc")
    public String helloMvc(@RequestParam(name = "name") String name, Model model) {
        // url에 파라미터로 name으로 들어오는걸 받음!
        model.addAttribute("name", name);
        return "hello-template";
    }

    @GetMapping("hello-string")
    @ResponseBody
    public String helloString(@RequestParam(name="name") String name, Model model) {
        // ResponseBody : html의 body에 내가 직접 넣어주겠다
        // 데이터를 그대로 내린다.
        // 사실 큰 의미 X
        return "hello"+name; // ex) "hello spring"
    }

    @GetMapping("hello-api")
    @ResponseBody
    public Hello helloApi(@RequestParam(name="name") String name, Model model) {
        Hello hello = new Hello(); // 자동완성 : command shift enter
        hello.setName(name);
        // 객체를 json형태로 전달함 {key : value}
        // 최근에는 json방식으로 통일됨 - 스프링도 기본이 객체를 반환하고 @ResponseBody = JSON반환
        return hello;
    }

    public class Hello {
        private String name;

        // getter setter: JAVA BEAN 표준 방식 (private변수를 public 메소드로 접근)
        // property 접근 방식이라고도 함
        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }
}
